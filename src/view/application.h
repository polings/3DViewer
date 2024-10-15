#ifndef INC_3D_VIEWER_SRC_VIEW_APPLICATION_H
#define INC_3D_VIEWER_SRC_VIEW_APPLICATION_H

#include <QFileDialog>
#include <QMainWindow>
#include <QObject>
#include <QString>

#include "../controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Application;
}
QT_END_NAMESPACE

class Application : public QMainWindow {
  Q_OBJECT

 public:
  Application(QWidget* parent = nullptr, s21::Controller* controller = nullptr);
  ~Application();

 private slots:
  void on_load_clicked();
  void on_zoom_in_clicked();
  void on_zoom_out_clicked();
  void on_move_down_clicked();
  void on_move_left_clicked();
  void on_move_right_clicked();
  void on_move_up_clicked();
  void on_move_in_clicked();
  void on_move_out_clicked();

  void on_rotate_down_around_x_clicked();
  void on_rotate_right_around_y_clicked();
  void on_rotate_left_around_y_clicked();
  void on_rotate_up_around_x_clicked();
  void on_rotate_right_around_z_clicked();
  void on_rotate_left_around_z_clicked();

 private:
  Ui::Application* ui;
  s21::Controller* controller_;
  double x_step;
  double y_step;
  double z_step;
};
#endif  // AINC_3D_VIEWER_SRC_VIEW_APPLICATION_H
