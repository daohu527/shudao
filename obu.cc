#include "obu.h"

#include "common_msg/bsm_msg/bsm_msg.pb.h"

#include "common/participant.h"

namespace shudao {
namespace app {

OBU::OBU() {

}

OBU::~OBU() {

}

void OBU::BSMCallback(const BasicSafetyMessage& msg) {
  common::ParticipantPtr participant;
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

void OBU::RSUCallback(const Message& msg) {
  switch (msg) {
    case BasicSafetyMessage:
      BSMCallback(msg);
      break;
    case RoadSideInformation:
      RSICallback(msg);
      break;
    case RoadsideSafetyMessage:
      RSMCallback(msg);
      break;
    case SPAT:
      SPATCallback(msg);
      break;
    case MapData:
      MapCallback(msg);
      break;
    default:
      break;
  }
}

void OBU::StatusCallback(const Status &msg) {
  // msg to status
  ego_impl_->AddStatus(status);
}

void OBU::RequestCallback(const Request &msg) {
  mqtt_cli_->Send(msg);
}

void OBU::CarCallback(const Message &msg) {
  StatusCallback();
  RequestCallback();
}

bool OBU::Init() {
  // 1. Init network
  mqtt_cli_->Init();
  grpc_cli_->Init();

  // 1.1 set callback to receive msgs
  // mqtt_cli_->AddCallback(RSUCallback);
  // grpc_cli_->AddCallback(CarCallback);

  // 2. Init scenarios
  // Use mqtt_cli_\grpc_cli_ to send msgs
  // ScenarioFactory::CreateScenarios(mqtt_cli_, grpc_cli_);
  return true;
}

void OBU::Process() {
  for (auto scenario : scenarios_) {
    if(scenario->Condition(ego_impl_, env_impl_)) {
      scenario->Notify();
    }
  }
}

}  // namespace app
}  // namespace shudao

int main(int argc, char **argv) {
  ros::init(argc, argv, "obu");
  ros::spin();
}
