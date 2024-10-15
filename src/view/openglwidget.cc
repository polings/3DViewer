#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent, Application *application_ptr,
                           s21::Controller *controller_ptr)
    : QOpenGLWidget(parent),
      application_ptr_(application_ptr),
      controller_(controller_ptr) {
  QSurfaceFormat format;
  format.setDepthBufferSize(16);
  setFormat(format);
}

void OpenGLWidget::initializeGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
}

void OpenGLWidget::resizeGL(int w, int h) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0, 0, w, h);
  glLoadIdentity();
}

void OpenGLWidget::paintGL() {
  if (controller_ == nullptr) {
    return;
  }
  glLoadIdentity();
  SetupPerspective();
  if (controller_->CorrectObject()) {
    DrawLines();
    PrintVertexes();
  }
}

void OpenGLWidget::DrawLines() {
  glLineWidth(1.0);
  glColor3d(255, 255, 255);
  std::vector<s21::Vertex> vertexes = controller_->getVertexes();
  std::vector<s21::Facet> polygons = controller_->getFacets();
  for (auto &poly : polygons) {
    glBegin(GL_LINE_LOOP);
    for (auto &it : poly.vertex_indexes) {
      glVertex3d(vertexes[it].x, vertexes[it].y, vertexes[it].z);
    }
    glEnd();
  }
}

void OpenGLWidget::PrintVertexes() {
  glPointSize(3.0);
  glColor3d(255, 255, 255);
  glBegin(GL_POINTS);
  for (auto &vertex : controller_->getVertexes()) {
    glVertex3d(vertex.x, vertex.y, vertex.z);
  }
  glEnd();
}

void OpenGLWidget::SetupPerspective() {
  double maxCoord = controller_->getMaxCoord();
  if (maxCoord <= 1) {
    maxCoord *= 3;
  } else {
    maxCoord *= 2;
  }

  GLdouble zNear = 0.01;
  GLdouble zFar = maxCoord * 1000;
  if (maxCoord <= 0.5) {
    maxCoord = 2;
  }
  GLdouble fovY = 90;
  GLdouble fH = tan(fovY / 360 * M_PI) * zNear;
  GLdouble fW = fH * ASPECT_RATIO;
  glFrustum(-fW, fW, -fH, fH, zNear, zFar);
  glTranslatef(0, 0, -maxCoord);
}
