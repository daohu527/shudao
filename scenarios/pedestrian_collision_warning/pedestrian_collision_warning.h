#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class PedestrianCollisionWarning : public Scenario {
 public:
  PedestrianCollisionWarning() = default;
  virtual ~PedestrianCollisionWarning() = default;

  void Condition() override;

  void Notify(const RoadsideSafetyMessage &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
