
#include "impl/env_impl.h"

namespace shudao {
namespace impl {

EnvImpl::EnvImpl() {

}

EnvImpl::~EnvImpl() {

}

bool EnvImpl::AddParticipant(const ParticipantPtr& participant) {
  participants_.Add(participant.id(), participant);
  return true;
}

bool EnvImpl::DelParticipant(const ParticipantPtr& participant) {
  participants_.Del(participant.id());
  return true;
}

bool EnvImpl::GetParticipant(ID id, ParticipantPtr participant) {
  participant = participants_.Get(id);
  return true;
}

bool EnvImpl::GetNearBy(Vec2D point, double distance,
                std::vector<ParticipantPtr>* participants) {
  participants_.GetAll();
}

}  // namespace impl
}  // namespace shudao
