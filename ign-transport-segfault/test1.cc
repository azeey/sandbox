#include <thread>
#include <ignition/transport/Node.hh>
#include <ignition/plugin/Loader.hh>

#include "TestSubscriber.hh"
using namespace ignition;

int main(int argc, char *argv[])
{
  ignition::plugin::Loader loader;
  auto pluginNames = loader.LoadLib(SUBSCRIBER_LIB_PATH);
  auto plugin = loader.Factory<TestSubscriberBase>(*pluginNames.begin());

  std::thread th{std::bind(&TestSubscriberBase::Run, plugin)};

  transport::Node node;
  auto pub = node.Advertise<msgs::Int32>("/data");

  msgs::Int32 msg;
  pub.Publish(msg);

  th.join();

  return 0;
}
