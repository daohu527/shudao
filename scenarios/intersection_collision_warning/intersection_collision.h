#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class IntersectionCollision : public Scenario<RoadsideSafetyMessage> {
 public:
  IntersectionCollision() = default;
  virtual ~IntersectionCollision() = default;

  void Condition() override;
  
  void Notify(const RoadsideSafetyMessage &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
