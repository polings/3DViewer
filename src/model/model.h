#ifndef INC_3D_VIEWER_SRC_MODEL_MODEL_H_
#define INC_3D_VIEWER_SRC_MODEL_MODEL_H_

#include "object.h"
#include "object_modify_strategy/strategy_modify.h"

namespace s21 {

class Model {
 public:
  Object& OpenObject(const std::string& file_name);

  bool CheckCorrect() { return object_.getValid(); }

  std::vector<Vertex> getVertexes() { return object_.getVertexes(); }
  std::vector<Facet> getFacets() { return object_.getFacets(); }
  size_t getEdges() const { return object_.getEdgesSize(); }
  double getMaxX() const { return object_.getMaxX(); }
  double getMaxY() const { return object_.getMaxY(); }
  double getMaxZ() const { return object_.getMaxZ(); }
  double getMaxCoord() const { return object_.getMaxCoordinate(); }

  void CenteringObject();
  void MoveX(double x_value);
  void MoveY(double y_value);
  void MoveZ(double z_value);
  void RotateX(double angle);
  void RotateY(double angle);
  void RotateZ(double angle);
  void Zoom(double scale);

 private:
  Object object_;
};
}  // namespace s21

#endif  // INC_3D_VIEWER_SRC_MODEL_MODEL_H_
