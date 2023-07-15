#pragma once

#include <vector>

#include "network/mqtt_client.h"
#include "network/grpc_client.h"
#include "impl/ego_impl.h"
#include "impl/env_impl.h"

namespace shudao {
namespace app {

class OBU {
 public:
  OBU();
  virtual ~OBU();

  bool Init();

  void Process();

 private:
  impl::EnvImpl env_impl_;
  impl::EgoImpl ego_impl_;
  std::vector<Scenario<BasicSafetyMessage>> scenarios_;

  std::shared_ptr<network::MQTTClient> mqtt_cli_;
  std::shared_ptr<network::GrpcClient> grpc_cli_;
};

}  // namespace app
}  // namespace shudao
