#ifndef INC_3D_VIEWER_SRC_MODEL_OBJECT_MODIFY_STRATEGY_MODIFY_H_
#define INC_3D_VIEWER_SRC_MODEL_OBJECT_MODIFY_STRATEGY_MODIFY_H_

#include "../object.h"

namespace s21 {

class Object;

class Modify {
 public:
  virtual ~Modify() = default;

  virtual void modify(Object& object) = 0;
};

}  // namespace s21

#endif  // INC_3D_VIEWER_SRC_MODEL_OBJECT_MODIFY_STRATEGY_MODIFY_H_
