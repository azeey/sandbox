#include <thread>
#include <memory>
#include <ignition/transport/Node.hh>

#include "TestSubscriber.hh"
using namespace ignition;

int main(int argc, char *argv[])
{
  auto plugin = std::make_shared<TestSubscriber>();
  std::thread th{std::bind(&TestSubscriberBase::Run, plugin)};

  transport::Node node;
  auto pub = node.Advertise<msgs::Int32>("/data");

  msgs::Int32 msg;
  pub.Publish(msg);

  th.join();

  return 0;
}
