#pragma once

namespace shudao {
namespace lib {

class Vec2D {
 public:
  Vec2D() = default;
  Vec2D(double x, double y) : x_(x), y_(y) {}

  double InnerProd(const Vec2D& other) const;

  double CrossProd(const Vec2D& other) const;

 private:
  double x_;
  double y_;
};


}
}