#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class RoadHazardWarning : public Scenario<RoadsideSafetyMessage> {
 public:
  RoadHazardWarning() = default;
  virtual ~RoadHazardWarning() = default;

  void Condition() override;
  
  void Notify(const RoadsideSafetyMessage &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
