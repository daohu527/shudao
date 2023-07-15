#pragma once

#include "common/participant.h"

namespace shudao {
namespace impl {

class EgoImpl {
 public:
  using ParticipantPtr = common::ParticipantPtr;

 public:
  EgoImpl();
  virtual ~EgoImpl();

  void AddStatus(Status status);

  ParticipantPtr GetEgo() const { return ego_; }

 private:
  ParticipantPtr ego_;
};

}  // namespace impl
}  // namespace shudao
