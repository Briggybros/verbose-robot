#include "bvh.h"

using namespace std;
using glm::vec3;

const float rt3b3 = sqrtf(3) / 3.f;

const vec3 planeSetNormals[7] = {vec3(1, 0, 0),
                                 vec3(0, 1, 0),
                                 vec3(0, 0, 1),
                                 vec3(rt3b3, rt3b3, rt3b3),
                                 vec3(-rt3b3, rt3b3, rt3b3),
                                 vec3(-rt3b3, -rt3b3, rt3b3),
                                 vec3(rt3b3, -rt3b3, rt3b3)};

Extents::Extends() {
  for (uint8_t i = 0; i < 7; i++) d[i][0] = INFINITY, d[i][1] = -INFINITY;
}

BVH::BVH(vector<Shape *> shapes) {
  extents = new Extents[shapes.size()];
  for (uint32_t i = 0; i < shapes.size(); ++i) {
    for (uint8_t j = 0; j < 7; ++j) {
      shapes[i].computeBounds(planeSetNormals[j], extents[i].d[j][0],
                               extents[i].d[j][1]);
    }
  }
}