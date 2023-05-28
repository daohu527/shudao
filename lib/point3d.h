#pragma once

namespace shudao {
namespace lib {

class Point3D {
 public:
  Point3D(double x, double y, double z) : x_(x), y_(y), z_(z) {}
  virtual ~Point3D() {}

 private:
  double x_;
  double y_;
  double z_;
};

} // namespace lib
} // namespace shudao
