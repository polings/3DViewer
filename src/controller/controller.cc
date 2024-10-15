#include "controller.h"

s21::Object& s21::Controller::OpenObject(const std::string& file_name) {
  Object& object = model_->OpenObject(file_name);
  return object;
}

void s21::Controller::MoveX(double value) { model_->MoveX(value); }

void s21::Controller::MoveY(double value) { model_->MoveY(value); }

void s21::Controller::MoveZ(double value) { model_->MoveZ(value); }

void s21::Controller::Zoom(double value) { model_->Zoom(value); }

void s21::Controller::RotateAroundX(double value) { model_->RotateX(value); }

void s21::Controller::RotateAroundY(double value) { model_->RotateY(value); }

void s21::Controller::RotateAroundZ(double value) { model_->RotateZ(value); }
