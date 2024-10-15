#ifndef INC_3D_VIEWER_SRC_MODEL_OBJECT_MODIFY_STRATEGY_OBJECT_SCALE_H_
#define INC_3D_VIEWER_SRC_MODEL_OBJECT_MODIFY_STRATEGY_OBJECT_SCALE_H_

#include "../object.h"
#include "modify.h"

namespace s21 {
class ObjectScale : public Modify {
 public:
  ObjectScale(double scaling_value) : scaling_value_(scaling_value){};
  void modify(Object& object) override;

 private:
  double scaling_value_;
};
}  // namespace s21
#endif  // INC_3D_VIEWER_SRC_MODEL_OBJECT_MODIFY_STRATEGY_OBJECT_SCALE_H_
