#include "object_scale.h"

namespace s21 {
void ObjectScale::modify(Object& object) {
  for (auto& point : object.vertexes_) {
    point.x *= scaling_value_;
    point.y *= scaling_value_;
    point.z *= scaling_value_;
  }
}
}  // namespace s21