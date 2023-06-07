#include "car.h"


namespace shudao {
namespace app {

Car::Car() {

}

Car::~Car() {

}

void Car::PoseCallback(const Pose& msg) {

}


bool Car::Init() {
  ros::NodeHandle n;
  
  ros::Subscriber pose_sub = n.subscribe("pose", 1000, PoseCallback);    

  return true;
}


}  // namespace app
}  // namespace shudao

int main(int argc, char **argv) {
  ros::init(argc, argv, "car");
  ros::spin();
}
