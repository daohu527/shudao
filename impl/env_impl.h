#pragma once

#include <string>
#include <vector>

#include "lib/expire_lru_cache.h"
#include "lib/vec2d.h"
#include "common/non_motor_vehicle.h"
#include "common/pedestrian.h"
#include "common/vehicle.h"

namespace shudao {
namespace impl {

class EnvImpl {
 public:
  using Vec2D = shudao::lib::Vec2D;
  using ParticipantPtr = common::ParticipantPtr;
  using ParticipantCache =
            shudao::lib::ExpireLRUCache<std::string, ParticipantPtr>;

 public:
  EnvImpl();
  virtual ~EnvImpl();

  bool AddParticipant(const ParticipantPtr& participant);
  bool DelParticipant(const ParticipantPtr& participant);
  bool GetParticipant(std::string id, ParticipantPtr participant) const;

  bool GetNearBy(Vec2D point, double distance,
                 std::vector<ParticipantPtr>* participants);

 private:
  ParticipantCache participants_;
};

}  // namespace impl
}  // namespace shudao
