#ifndef INC_3D_VIEWER_SRC_MODEL_OBJECT_MODIFY_STRATEGY_OBJECT_CENTERING_H_
#define INC_3D_VIEWER_SRC_MODEL_OBJECT_MODIFY_STRATEGY_OBJECT_CENTERING_H_

#include "../object.h"
#include "modify.h"

namespace s21 {

class Object;

class ObjectCentering : public Modify {
 public:
  void modify(Object& object) override;
};

}  // namespace s21
#endif  // INC_3D_VIEWER_SRC_MODEL_OBJECT_MODIFY_STRATEGY_OBJECT_CENTERING_H_
