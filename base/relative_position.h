#pragma once

#include "base/vec2d.h"

namespace shudao {
namespace base {

enum RelativePosition {
  FRONT = 0,
  BACK = 1,
  LEFT_FRONT = 2,
  RIGHT_FRONT = 3,
  LEFT_BACK = 4,
  RIGHT_BACK = 5,
  UNKNOWN = 6,
};

RelativePosition GetRelativePosition(
    const double ths_x, 
    const double ths_y,
    const double other_x,
    const double other_y) {
  Vec2d ths(ths_x, ths_y);
  Vec2d other(other_x, other_y);
  return GetRelativePosition(ths, other);               
}

RelativePosition GetRelativePosition(
    const Vec2d& ths, 
    const Vec2d& other) {
  
  double inner = ths.InnerProd(other);
  double cross = ths.CrossProd(other);

  // Front
  if (inner > 0 && cross > 0) {
    return RelativePosition::LEFT_FRONT;
  } else if (inner > 0 && cross < 0) {
    return RelativePosition::RIGHT_FRONT;
  // Back
  } else if (inner < 0 && cross > 0) { 
    return RelativePosition::LEFT_BACK;
  } else if (inner < 0 && cross < 0) {
    return RelativePosition::RIGHT_BACK;
  } else {
    return RelativePosition::UNKNOWN;
  }
}

bool IsFront(const Vec2d& ths, 
             const Vec2d& other) {
  return ths.InnerProd(other) > 0;
}

double Distance(
    const double x1, 
    const double y1,
    const double x2,
    const double y2) {
  return hypot(x1 - x2, y1 - y2);
}

}
}