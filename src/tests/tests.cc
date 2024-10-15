#include <gtest/gtest.h>

#include "../model/model.h"

TEST(Model, test_1) {
  s21::Object object("tests/testFiles/cube.obj");
  std::vector<s21::Vertex> vertexes = {
      {1.000000, 1.000000, -1.000000},  {1.000000, -1.000000, -1.000000},
      {1.000000, 1.000000, 1.000000},   {1.000000, -1.000000, 1.000000},
      {-1.000000, 1.000000, -1.000000}, {-1.000000, -1.000000, -1.000000},
      {-1.000000, 1.000000, 1.000000},  {-1.000000, -1.000000, 1.000000}};
  std::vector<s21::Facet> facets = {
      s21::Facet{{0, 4, 6, 2}}, s21::Facet{{3, 2, 6, 7}},
      s21::Facet{{7, 6, 4, 5}}, s21::Facet{{5, 1, 3, 7}},
      s21::Facet{{1, 0, 2, 3}}, s21::Facet{{5, 4, 0, 1}}};
  ASSERT_TRUE(object.getValid());
  ASSERT_EQ(object.getVertexes(), vertexes);
  ASSERT_EQ(object.getFacets(), facets);
  ASSERT_EQ(object.getMaxCoordinate(), 1);
  ASSERT_EQ(object.getEdgesSize(), static_cast<unsigned long>(12));
  ASSERT_EQ(object.getVertexes().size(), static_cast<unsigned long>(8));
}

TEST(Model, test_2) {
  s21::Object object("tests/testFiles/fail.obj");
  ASSERT_FALSE(object.getValid());
}

TEST(Model, test_3) {
  s21::Object object1("tests/testFiles/cube.obj");
  s21::Object object2("tests/testFiles/cube.obj");
  ASSERT_EQ(object1, object2);
}

TEST(Model, test_4) {
  s21::Object object1("tests/testFiles/cube.obj");
  s21::Object object2(std::move(object1));
  ASSERT_FALSE(object1 == object2);
}

TEST(Model, test_5) {
  s21::Object object1("tests/testFiles/cube.obj");
  s21::Object object2(object1);
  ASSERT_EQ(object1, object2);
}

TEST(Model, test_6) {
  s21::Object object1("tests/testFiles/cube.obj");
  s21::Object object2;
  object2 = object1;
  ASSERT_EQ(object1, object2);
}

TEST(Model, test_7) {
  s21::Object object("tests/testFiles/no_such_file.obj");
  ASSERT_FALSE(object.getValid());
}

TEST(Model, test_8) {
  s21::Object object("tests/testFiles/fail_no_vertices.obj");
  ASSERT_FALSE(object.getValid());
}

TEST(Model, test_9) {
  s21::Object object("tests/testFiles/no_facets.obj");
  ASSERT_FALSE(object.getValid());
}

TEST(Model, test_10) {
  s21::Object object1(
      "/Users/hakekett/CPP4_3DViewer_v2.0-1/src/tests/testFiles/cube.obj");
  s21::Object object2;
  s21::Object object3(
      "/Users/hakekett/CPP4_3DViewer_v2.0-1/src/tests/testFiles/cube.obj");
  object2 = std::move(object1);
  ASSERT_TRUE(object3 == object2);
}

TEST(Model, test_11) {
  s21::Object object("tests/testFiles/negative_index.obj");
  ASSERT_TRUE(object.getValid());
}

TEST(Model, test_12) {
  s21::Object object1("tests/testFiles/cube.obj");
  ASSERT_EQ(object1, object1);
}

TEST(Model, test_13) {
  s21::Object object("tests/testFiles/test_cube.obj");
  object.modify(std::make_unique<s21::ObjectTranslation>(1, 0, 0));
  std::vector<s21::Vertex> vertexes = {{2.000000, 1.000000, -1.000000},
                                       {2.000000, -1.000000, -1.000000},
                                       {0.000000, 1.000000, 1.000000}};
  ASSERT_EQ(object.getVertexes(), vertexes);
}

TEST(Model, test_14) {
  s21::Object object("tests/testFiles/test_cube.obj");
  object.modify(std::make_unique<s21::ObjectTranslation>(0, 1, 0));
  std::vector<s21::Vertex> vertexes = {{1.000000, 2.000000, -1.000000},
                                       {1.000000, 0.000000, -1.000000},
                                       {-1.000000, 2.000000, 1.000000}};
  ASSERT_EQ(object.getVertexes(), vertexes);
}

TEST(Model, test_15) {
  s21::Object object("tests/testFiles/test_cube.obj");
  object.modify(std::make_unique<s21::ObjectTranslation>(0, 0, 1));
  std::vector<s21::Vertex> vertexes = {{1.000000, 1.000000, 0.000000},
                                       {1.000000, -1.000000, 0.000000},
                                       {-1.000000, 1.000000, 2.000000}};
  ASSERT_EQ(object.getVertexes(), vertexes);
}

TEST(Model, test_16) {
  s21::Object object("tests/testFiles/test_cube.obj");
  object.modify(std::make_unique<s21::ObjectRotate>(5, s21::Axis::kAxisX));
  std::vector<s21::Vertex> vertexes = {
      {1, 0.90903895534408741, -1.0833504408394037},
      {1, -1.0833504408394037, -0.90903895534408741},
      {-1, 1.0833504408394037, 0.90903895534408741}};
  ASSERT_EQ(object.getVertexes(), vertexes);
}

TEST(Model, test_17) {
  s21::Object object("tests/testFiles/test_cube.obj");
  object.modify(std::make_unique<s21::ObjectRotate>(5, s21::Axis::kAxisY));
  std::vector<s21::Vertex> vertexes = {
      {0.90903895534408741, 1, -1.0833504408394037},
      {0.90903895534408741, -1, -1.0833504408394037},
      {-0.90903895534408741, 1, 1.0833504408394037}};
  ASSERT_EQ(object.getVertexes(), vertexes);
}

TEST(Model, test_18) {
  s21::Object object("tests/testFiles/test_cube.obj");
  object.modify(std::make_unique<s21::ObjectRotate>(5, s21::Axis::kAxisZ));
  std::vector<s21::Vertex> vertexes = {
      {1.0833504408394037, 0.90903895534408741, -1},
      {0.90903895534408741, -1.0833504408394037, -1},
      {-0.90903895534408741, 1.0833504408394037, 1}};
  ASSERT_EQ(object.getVertexes(), vertexes);
}

TEST(Model, test_19) {
  s21::Object object("tests/testFiles/uncentred_object.obj");
  object.modify(std::make_unique<s21::ObjectCentering>(s21::ObjectCentering()));
  std::vector<s21::Vertex> vertexes = {
      {2.000000, 0.66666666666666674, -0.66666666666666674},
      {-2.000000, -1.33333333333333333, -0.66666666666666674},
      {0.000000, 0.66666666666666674, 1.33333333333333333}};
  ASSERT_EQ(object.getVertexes(), vertexes);
}

TEST(Model, test_20) {
  s21::Object object("tests/testFiles/test_cube.obj");
  object.modify(std::make_unique<s21::ObjectScale>(2.1));
  std::vector<s21::Vertex> vertexes = {
      {2.1, 2.1, -2.1}, {2.1, -2.1, -2.1}, {-2.1, 2.1, 2.1}};
  ASSERT_EQ(object.getVertexes(), vertexes);
}
