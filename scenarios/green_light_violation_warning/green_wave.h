#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class GreenWave : public Scenario<RoadSideInformation> {
 public:
  GreenWave() = default;
  virtual ~GreenWave() = default;

  void Condition() override;
  
  void Notify(const RoadSideInformation &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
