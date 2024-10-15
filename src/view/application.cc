#include "application.h"

#include "ui_application.h"

Application::Application(QWidget* parent, s21::Controller* controller)
    : QMainWindow(parent), controller_(controller), ui(new Ui::Application) {
  ui->setupUi(this);
  ui->openGLWidget->setApplicationWidgetPtr(this);
  ui->openGLWidget->setControllerPtr(controller_);
}

Application::~Application() { delete ui; }

void Application::on_load_clicked() {
  QString file_path = QFileDialog::getOpenFileName(
      this, tr("Open object file"), "./objFiles", "Text files (*.obj)");

  if (file_path.length()) {
    QFileInfo file_info(file_path);
    ui->path_to_file->setText(file_path);
    QString file_name = file_info.fileName();
    ui->object_name->setText(file_name);

    controller_->OpenObject(file_path.toStdString());

    if (controller_->CorrectObject()) {
      ui->edges_display->setText(
          QString::number(controller_->getObjectEdgesCount()) + " ");
      ui->vertices_display->setText(
          QString::number(controller_->getVertexes().size()) + " ");

      controller_->ObjectPlacement();

      x_step = controller_->getMaxX() * 0.3;
      y_step = controller_->getMaxY() * 0.3;
      z_step = controller_->getMaxZ() * 0.3;
    } else {
      ui->path_to_file->setText(
          "Incorrect object file. Please reload correct file");
      ui->edges_display->setText("0");
      ui->vertices_display->setText("0");
    }
  }
}

void Application::on_move_up_clicked() {
  controller_->MoveY(y_step);
  ui->openGLWidget->update();
}

void Application::on_move_down_clicked() {
  controller_->MoveY(-y_step);
  ui->openGLWidget->update();
}

void Application::on_move_left_clicked() {
  controller_->MoveX(-x_step);
  ui->openGLWidget->update();
}

void Application::on_move_right_clicked() {
  controller_->MoveX(x_step);
  ui->openGLWidget->update();
}

void Application::on_move_in_clicked() {
  controller_->MoveZ(z_step);
  ui->openGLWidget->update();
}

void Application::on_move_out_clicked() {
  controller_->MoveZ(-z_step);
  ui->openGLWidget->update();
}

void Application::on_zoom_in_clicked() {
  controller_->Zoom(1.1);
  ui->openGLWidget->update();
}

void Application::on_zoom_out_clicked() {
  controller_->Zoom(0.9);
  ui->openGLWidget->update();
}

void Application::on_rotate_up_around_x_clicked() {
  controller_->RotateAroundX(5);
  ui->openGLWidget->update();
}

void Application::on_rotate_down_around_x_clicked() {
  controller_->RotateAroundX(-5);
  ui->openGLWidget->update();
}

void Application::on_rotate_right_around_y_clicked() {
  controller_->RotateAroundY(5);
  ui->openGLWidget->update();
}

void Application::on_rotate_left_around_y_clicked() {
  controller_->RotateAroundY(-5);
  ui->openGLWidget->update();
}

void Application::on_rotate_right_around_z_clicked() {
  controller_->RotateAroundZ(5);
  ui->openGLWidget->update();
}

void Application::on_rotate_left_around_z_clicked() {
  controller_->RotateAroundZ(-5);
  ui->openGLWidget->update();
}
