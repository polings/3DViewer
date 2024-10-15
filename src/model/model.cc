#include "model.h"

namespace s21 {
Object &Model::OpenObject(const std::string &file_name) {
  object_.Clear();
  object_.ParseFile(file_name);
  return object_;
}

void Model::CenteringObject() {
  object_.modify(std::make_unique<ObjectCentering>(ObjectCentering()));
}

void Model::MoveX(double x_value) {
  object_.modify(std::make_unique<ObjectTranslation>(x_value, 0, 0));
}

void Model::MoveY(double y_value) {
  object_.modify(std::make_unique<ObjectTranslation>(0, y_value, 0));
}

void Model::MoveZ(double z_value) {
  object_.modify(std::make_unique<ObjectTranslation>(0, 0, z_value));
}

void Model::RotateX(double angle) {
  object_.modify(std::make_unique<ObjectRotate>(angle, Axis::kAxisX));
}

void Model::RotateY(double angle) {
  object_.modify(std::make_unique<ObjectRotate>(angle, Axis::kAxisY));
}

void Model::RotateZ(double angle) {
  object_.modify(std::make_unique<ObjectRotate>(angle, Axis::kAxisZ));
}

void Model::Zoom(double scale) {
  object_.modify(std::make_unique<ObjectScale>(scale));
}
}  // namespace s21
