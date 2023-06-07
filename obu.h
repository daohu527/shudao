#pragma once

#include <vector>

namespace shudao {
namespace app {

class OBU {
 public:
  OBU();
  virtual ~OBU();

  bool Init();

  void Process();

 private:
  EnvImpl env_impl_;
  EgoImpl ego_impl_;
  std::vector<Scenario<BasicSafetyMessage>> scenarios_;

  std::shared_ptr<MQTTClient> mqtt_cli_;
  std::shared_ptr<GrpcClient> grpc_cli_;  
};

}  // namespace app
}  // namespace shudao
