#include "object_translation.h"

namespace s21 {
void ObjectTranslation::modify(Object& object) {
  for (auto& point : object.vertexes_) {
    point.x += x_;
    point.y += y_;
    point.z += z_;
  }
}
}  // namespace s21
