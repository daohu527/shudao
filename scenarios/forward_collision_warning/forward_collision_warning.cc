#include "scenarios/forward_collision_warning/forward_collision_warning.h"


namespace shudao {
namespace scenario {

bool ForwardCollision::Condition(const impl::EgoImpl &ego_impl,
                                 const impl::EnvImpl &env_impl) {
  lib::Vec2D pos = ego_impl->GetPosition();
  std::vector<ParticipantPtr> participants;
  env_impl->GetNearBy(pos, alert_distance_, &participants);

  ParticipantPtr ego = ego_impl->GetEgo();
  ParticipantPtr nearest_front_p = nullptr;
  double nearest_distance = alert_distance_;
  for (ParticipantPtr p : participants) {
    if(IsSameLane(ego, p) && nearest_distance > Distance(ego, p)) {
      nearest_front_p = p;
      nearest_distance = Distance(ego, p);
    }
  }

  if (nearest_front_p) {
    BasicSafetyMessage msg;
    ConstructMsg(nearest_front_p, &msg);
    Notify(msg);
  }

  return true;
}

bool ForwardCollision::Notify(const BasicSafetyMessage &msg) {
  return true;
}

bool ForwardCollision::IsSameLane(const ParticipantPtr &ego,
                                  const ParticipantPtr &other) {
  return true;
}

}  // namespace scenario
}  // namespace shudao
