#ifndef INC_3D_VIEWER_SRC_MODEL_OBJECT_H_
#define INC_3D_VIEWER_SRC_MODEL_OBJECT_H_

#include <cmath>
#include <fstream>
#include <iostream>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

namespace s21 {

class Modify;

struct Vertex {
  bool operator==(const Vertex &other) const {
    return x == other.x && y == other.y && z == other.z;
  }

  double x;
  double y;
  double z;
};

struct Facet {
  bool operator==(const Facet &other) const {
    return vertex_indexes == other.vertex_indexes;
  }

  std::vector<int> vertex_indexes;
};

struct Coordinates {
  Coordinates() {
    x_min_ = .0f;
    x_max_ = .0f;
    y_min_ = .0f;
    y_max_ = .0f;
    z_min_ = .0f;
    z_max_ = .0f;
    empty_ = true;
  }

  void UpdateMinMaxValues(Vertex vertex);

  double getMaxCoord() const;

  void clear();

  double getMaxX() const { return x_max_; }

  double getMaxY() const { return y_max_; }

  double getMaxZ() const { return z_max_; }

  bool empty_;
  double x_max_, y_max_, z_max_;
  double x_min_, y_min_, z_min_;
};

class Object {
 public:
  Object();

  Object(const std::string &file_name);

  Object(const Object &other);

  Object(const Object &&other);

  Object &operator=(const Object &other);

  Object &operator=(Object &&other);

  ~Object() = default;

  bool operator==(const Object &other) const;

  void ParseFile(const std::string &file_name);

  void Clear();

  void ObjectCentering();

  void modify(std::unique_ptr<Modify> strategy);

  std::vector<Vertex> getVertexes() const { return vertexes_; }

  std::vector<Facet> getFacets() const { return faceties_; }

  bool getValid() const { return is_correct_; }

  size_t getEdgesSize() const { return unique_edges_.size(); }

  double getMaxCoordinate() const { return coordinates_.getMaxCoord(); }

  double getMaxX() const { return coordinates_.getMaxX(); }

  double getMaxY() const { return coordinates_.getMaxY(); }

  double getMaxZ() const { return coordinates_.getMaxZ(); }

  std::vector<Vertex> vertexes_;

 private:
  std::vector<Facet> faceties_;
  std::set<std::pair<size_t, size_t>> unique_edges_;
  Coordinates coordinates_;
  bool is_correct_;

  void ParseVertex(std::string &line);

  void ParseFacet(std::string &line);

  size_t ParseFacetIndex(std::string &line, std::string &token);
};

}  // namespace s21

#endif  // INC_3D_VIEWER_SRC_MODEL_OBJECT_H_
