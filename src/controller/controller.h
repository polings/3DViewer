#ifndef INC_3D_VIEWER_SRC_CONTROLLER_CONTROLLER_H_
#define INC_3D_VIEWER_SRC_CONTROLLER_CONTROLLER_H_

#include <string>

#include "../model/model.h"

namespace s21 {

class Controller {
 public:
  explicit Controller(Model* model) : model_(model) {}

  Object& OpenObject(const std::string& file_name);

  void MoveY(double value);
  void MoveX(double value);
  void MoveZ(double value);

  void Zoom(double value);

  void RotateAroundX(double value);
  void RotateAroundY(double value);
  void RotateAroundZ(double value);

  bool CorrectObject() { return model_->CheckCorrect(); }
  size_t getObjectEdgesCount() { return model_->getEdges(); }
  std::vector<Vertex> getVertexes() { return model_->getVertexes(); }
  std::vector<Facet> getFacets() { return model_->getFacets(); }
  double getMaxX() const { return model_->getMaxX(); }
  double getMaxY() const { return model_->getMaxY(); }
  double getMaxZ() const { return model_->getMaxZ(); }

  double getMaxCoord() const { return model_->getMaxCoord(); }
  void ObjectPlacement() { model_->CenteringObject(); }

 private:
  Model* model_;
};

}  // namespace s21

#endif  // INC_3D_VIEWER_SRC_CONTROLLER_CONTROLLER_H_
