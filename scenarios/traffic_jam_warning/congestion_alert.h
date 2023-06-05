#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class CongestionAlert : public Scenario<RoadSideInformation> {
 public:
  CongestionAlert() = default;
  virtual ~CongestionAlert() = default;

  void Condition() override;
  
  void Notify(const RoadSideInformation &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
