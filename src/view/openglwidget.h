#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#define ASPECT_RATIO 1.42

#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>

#include "./controller/controller.h"
#include "./model/model.h"
#include "application.h"

class OpenGLWidget : public QOpenGLWidget {
  Q_OBJECT

 public:
  OpenGLWidget(QWidget* parent = nullptr,
               Application* application_ptr = nullptr,
               s21::Controller* controller_ptr = nullptr);

  void setApplicationWidgetPtr(Application* ptr) { application_ptr_ = ptr; }
  void setControllerPtr(s21::Controller* ptr) { controller_ = ptr; }

  GLuint indexesBuffer;
  int vertexesSize;
  int edgesSize;

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

 private:
  void DrawLines();
  void PrintVertexes();
  void SetupPerspective();

  Application* application_ptr_;
  s21::Controller* controller_;
};

#endif  // OPENGLWIDGET_H
