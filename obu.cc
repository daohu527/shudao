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
  ros::NodeHandle n;
  
  ros::Subscriber bsm_sub = n.subscribe("bsm_msg", 1000, BSMCallback);    
  ros::Subscriber rsi_sub = n.subscribe("rsi_msg", 1000, RSICallback);  
  ros::Subscriber rsm_sub = n.subscribe("rsm_msg", 1000, RSMCallback);  
  ros::Subscriber spat_sub = n.subscribe("spat_msg", 1000, SPATCallback);  
  ros::Subscriber map_sub = n.subscribe("map_msg", 1000, MapCallback); 
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
