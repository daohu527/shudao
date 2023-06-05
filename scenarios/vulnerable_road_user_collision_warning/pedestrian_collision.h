#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class PedestrianCollision : public Scenario<RoadsideSafetyMessage> {
 public:
  PedestrianCollision() = default;
  virtual ~PedestrianCollision() = default;

  void Condition() override;
  
  void Notify(const RoadsideSafetyMessage &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
