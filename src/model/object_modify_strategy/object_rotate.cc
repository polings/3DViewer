#include "object_rotate.h"

namespace s21 {
void ObjectRotate::modify(Object& object) {
  angle_ = angle_ * M_PI / 180;
  for (auto& point : object.vertexes_) {
    switch (axis_) {
      case Axis::kAxisX:
        RotateAxes(point.y, point.z);
        break;
      case Axis::kAxisY:
        RotateAxes(point.x, point.z);
        break;
      case Axis::kAxisZ:
        RotateAxes(point.x, point.y);
        break;
    }
  }
}

void ObjectRotate::RotateAxes(double& point1, double& point2) {
  double temp_1 = point1;
  double temp_2 = point2;
  point1 = cos(angle_) * temp_1 + sin(angle_) * temp_2;
  point2 = sin(angle_) * ((-1) * temp_1) + cos(angle_) * temp_2;
}
}  // namespace s21
