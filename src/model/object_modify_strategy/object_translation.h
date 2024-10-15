#ifndef INC_3D_VIEWER_SRC_MODEL_OBJECT_MODIFY_STRATEGY_OBJECT_TRANSLATION_H_
#define INC_3D_VIEWER_SRC_MODEL_OBJECT_MODIFY_STRATEGY_OBJECT_TRANSLATION_H_

#include "../object.h"
#include "modify.h"

namespace s21 {
class ObjectTranslation : public Modify {
 public:
  ObjectTranslation(double x_value, double y_value, double z_value)
      : x_(x_value), y_(y_value), z_(z_value){};
  void modify(Object& object) override;

 private:
  double x_, y_, z_;
};

}  // namespace s21
#endif  // INC_3D_VIEWER_SRC_MODEL_OBJECT_MODIFY_STRATEGY_OBJECT_TRANSLATION_H_
