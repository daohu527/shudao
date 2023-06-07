#include "obu.h"

#include "common_msg/bsm_msg/bsm_msg.pb.h"

namespace shudao {
namespace app {

OBU::OBU() {

}

OBU::~OBU() {

}

void OBU::BSMCallback(const BasicSafetyMessage& msg) {
  ParticipantPtr participant;
  env_impl_->AddParticipant(participant);
}

void OBU::RSICallback(const RoadSideInformation& msg) {

}

void OBU::RSMCallback(const RoadsideSafetyMessage& msg) {

}

void OBU::SPATCallback(const SPAT& msg) {

}

void OBU::MapCallback(const MapData& msg) {

}

bool OBU::Init() {
  client_->Init();
  return true;
}

void OBU::Process() {
  for (auto scenario : scenarios_) {
    scenario->Condition(ego_impl_, env_impl_);
  }
}

}  // namespace app
}  // namespace shudao

int main(int argc, char **argv) {
  ros::init(argc, argv, "obu");
  ros::spin();
}
