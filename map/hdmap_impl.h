#pragma once

#include <vector>

#include "common/traffic_light.h"

namespace shudao {
namespace map {

class HdmapImpl {
 public:
  void FindFrontTrafficLights(lib::Point3D ego_position, double distance,
                              std::vector<common::TrafficLight>* traffic_lights);
};

} // namespace map
} // namespace shudao
