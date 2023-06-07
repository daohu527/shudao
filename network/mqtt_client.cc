#include "network/mqtt_client.h"

#include "mqtt/async_client.h"

namespace shudao {
namespace network {

bool MQTTClient::Init() {
  sample_mem_persistence persist;
  cli_(ADDRESS, CLIENT_ID, &persist);

  callback cb;
  cli_.set_callback(cb);

  auto connOpts = mqtt::connect_options_builder() 
      .keep_alive_interval(20);
      .clean_session()
      .finalize();

  try {
    auto tok = cli_.connect(connOpts);
    auto rsp = tok->get_connect_response();
		if (!rsp.is_session_present())
			cli.subscribe(TOPIC, QOS)->wait();    

		while (true) {
			auto msg = cli.consume_message();
			if (!msg) break;
			cout << msg->get_topic() << ": " << msg->to_string() << endl;
		}

    // First use a message pointer.
    mqtt::message_ptr pubmsg = mqtt::make_message(PAYLOAD1);
    pubmsg->set_qos(QOS);
    cli_.publish(TOPIC, pubmsg);

    // Now try with itemized publish.

    cli_.publish(TOPIC, PAYLOAD2, strlen(PAYLOAD2)+1, 0, false);    
  }
  catch (const mqtt::persistence_exception& exc) {
    cerr << "Persistence Error: " << exc.what() << " ["
        << exc.get_reason_code() << "]" << endl;
    return false;
  }
  catch (const mqtt::exception& exc) {
    cerr << "Error: " << exc.what() << " ["
        << exc.get_reason_code() << "]" << endl;
    return false;
  }      

  return true;
}

}  // namespace network
}  // namespace shudao
