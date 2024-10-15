#include "object.h"

#include "object_modify_strategy/strategy_modify.h"

namespace s21 {
void Coordinates::clear() {
  x_min_ = y_min_ = z_min_ = 0;
  x_max_ = y_max_ = z_max_ = 0;
}

double Coordinates::getMaxCoord() const {
  double max_coord = std::abs(x_min_);
  max_coord = std::max(max_coord, std::abs(y_min_));
  max_coord = std::max(max_coord, std::abs(z_min_));
  max_coord = std::max(max_coord, std::abs(x_max_));
  max_coord = std::max(max_coord, std::abs(y_max_));
  max_coord = std::max(max_coord, std::abs(z_max_));
  return max_coord;
}

void Coordinates::UpdateMinMaxValues(s21::Vertex vertex) {
  if (empty_) {
    empty_ = false;
    x_min_ = x_max_ = vertex.x;
    y_min_ = y_max_ = vertex.y;
    z_min_ = z_max_ = vertex.z;
  } else {
    if (x_min_ > vertex.x) x_min_ = vertex.x;
    if (x_max_ < vertex.x) x_max_ = vertex.x;
    if (y_min_ > vertex.y) y_min_ = vertex.y;
    if (y_max_ < vertex.y) y_max_ = vertex.y;
    if (z_min_ > vertex.z) z_min_ = vertex.z;
    if (z_max_ < vertex.z) z_max_ = vertex.z;
  }
}

Object::Object()
    : vertexes_(),
      faceties_(),
      unique_edges_(),
      coordinates_(),
      is_correct_(false) {}

Object::Object(const std::string &file_name) : Object() {
  ParseFile(file_name);
}

Object::Object(const Object &other)
    : vertexes_(other.vertexes_),
      faceties_(other.faceties_),
      unique_edges_(other.unique_edges_),
      coordinates_(other.coordinates_),
      is_correct_(other.is_correct_) {}

Object::Object(const Object &&other)
    : vertexes_(std::move(other.vertexes_)),
      faceties_(std::move(other.faceties_)),
      unique_edges_(std::move(other.unique_edges_)),
      coordinates_(std::move(other.coordinates_)),
      is_correct_(other.is_correct_) {
  Clear();
}

Object &Object::operator=(const Object &other) {
  if (this != &other) {
    vertexes_ = other.vertexes_;
    faceties_ = other.faceties_;
    unique_edges_ = other.unique_edges_;
    coordinates_ = other.coordinates_;
    is_correct_ = other.is_correct_;
  }
  return *this;
}

Object &Object::operator=(Object &&other) {
  if (this != &other) {
    vertexes_ = std::move(other.vertexes_);
    faceties_ = std::move(other.faceties_);
    unique_edges_ = std::move(other.unique_edges_);
    coordinates_ = std::move(other.coordinates_);
    is_correct_ = other.is_correct_;
    other.is_correct_ = false;
  }
  return *this;
}

bool Object::operator==(const Object &other) const {
  if (this == &other) {
    return true;
  }
  return getValid() == other.getValid() && vertexes_ == other.getVertexes() &&
         getFacets() == other.getFacets();
}

void Object::modify(std::unique_ptr<Modify> strategy) {
  if (strategy) {
    strategy->modify(*this);
  }
}

void Object::ParseFile(const std::string &file_name) {
  std::ifstream object_file(file_name);
  if (object_file.is_open()) {
    is_correct_ = true;
    std::string line;
    while (std::getline(object_file, line) && is_correct_) {
      if (line.rfind("v ", 0) == 0) {
        ParseVertex(line);
      } else if (line.rfind("f ", 0) == 0) {
        ParseFacet(line);
      }
    }
    object_file.close();
  } else {
    std::cerr << "File open error: " << file_name << '\n';
    is_correct_ = false;
    return;
  }
}

void Object::ParseVertex(std::string &line) {
  std::istringstream ss(line.substr(2));
  Vertex vertex;
  if (ss >> vertex.x >> vertex.y >> vertex.z) {
    vertexes_.push_back(vertex);
    coordinates_.UpdateMinMaxValues(vertex);
  } else {
    std::cerr << "Vertex parse error: " << line << '\n';
    is_correct_ = false;
  }
}

void Object::ParseFacet(std::string &line) {
  std::istringstream iss(line.substr(2));
  Facet facet;
  facet.vertex_indexes.reserve(4);
  std::string token_with_index;

  std::vector<size_t> indices;
  while (iss >> token_with_index && is_correct_) {
    size_t index = ParseFacetIndex(line, token_with_index);
    facet.vertex_indexes.push_back(static_cast<int>(index));
    indices.push_back(index);
  }
  if (is_correct_) {
    faceties_.push_back(facet);

    size_t n = indices.size();
    for (size_t i = 0; i < n; ++i) {
      size_t index1 = indices[i];
      size_t index2 = indices[(i + 1) % n];
      if (index1 > index2) {
        std::swap(index1, index2);
      }
      unique_edges_.emplace(index1, index2);
    }
  }
}

size_t Object::ParseFacetIndex(std::string &line, std::string &token) {
  std::istringstream ss(token);
  int number = 0;
  ss >> number;
  if (ss.fail() || (number > (int)vertexes_.size()) ||
      (number < 0 && ((-1 * number) > (int)vertexes_.size()))) {
    std::cerr << "Facet parse error: " << line << '\n';
    is_correct_ = false;
  } else if (number < 0) {
    number = vertexes_.size() + (number + 1);
  }
  return number - 1;
}

void Object::Clear() {
  is_correct_ = false;
  coordinates_.clear();
  vertexes_.clear();
  faceties_.clear();
  unique_edges_.clear();
}
}  // namespace s21
