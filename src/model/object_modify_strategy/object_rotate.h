#ifndef INC_3D_VIEWER_SRC_MODEL_OBJECT_MODIFY_STRATEGY_OBJECT_ROTATE_H_
#define INC_3D_VIEWER_SRC_MODEL_OBJECT_MODIFY_STRATEGY_OBJECT_ROTATE_H_

#include "../object.h"
#include "modify.h"

namespace s21 {
enum class Axis { kAxisX, kAxisY, kAxisZ };

class ObjectRotate : public Modify {
 public:
  ObjectRotate(double angle, Axis axis) : angle_(angle), axis_(axis){};
  void modify(Object& object) override;
  void RotateAxes(double& point1, double& point2);

 private:
  double angle_;
  Axis axis_;
};

}  // namespace s21
#endif  // INC_3D_VIEWER_SRC_MODEL_OBJECT_MODIFY_STRATEGY_OBJECT_ROTATE_H_
