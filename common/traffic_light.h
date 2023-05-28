#pragma once

#include "lib/point3d.h"

namespace shudao {
namespace common {

class TrafficLight {
 public:
  TrafficLight() = default;
  virtual ~TrafficLight() = default;

 private:
  lib::Point3D position_;
};

} // namespace common
} // namespace shudao
