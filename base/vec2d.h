#pragma once

namespace shudao {
namespace base {

class Vec2d {
 public:
  Vec2d() = default;
  Vec2d(double x, double y) : x_(x), y_(y) {}

  double InnerProd(const Vec2d& other) const;
  
  double CrossProd(const Vec2d& other) const;

 private:
  double x_;
  double y_;
};


}
}