#include "object_centering.h"

namespace s21 {

void ObjectCentering::modify(Object& object) {
  double center_x = 0.0;
  double center_y = 0.0;
  double center_z = 0.0;
  int n = static_cast<int>(object.vertexes_.size());
  for (auto& point : object.vertexes_) {
    center_x += point.x;
    center_y += point.y;
    center_z += point.z;
  }
  center_x /= n;
  center_y /= n;
  center_z /= n;

  for (auto& point : object.vertexes_) {
    point.x -= center_x;
    point.y -= center_y;
    point.z -= center_z;
  }
}

}  // namespace s21
