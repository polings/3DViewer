#include <QApplication>

#include "controller/controller.h"
#include "model/model.h"
#include "view/application.h"
#include "view/openglwidget.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Model model;
  s21::Controller controller(&model);
  Application w(nullptr, &controller);
  w.setWindowTitle("3D viewer");
  w.show();
  return a.exec();
}
