#include <ignition/plugin/Register.hh>
#include <ignition/gazebo/components/World.hh>
#include <ignition/gazebo/components/Joint.hh>
#include "TestPlugin.hh"

namespace components = ignition::gazebo::components;
TestPlugin::~TestPlugin()
{
  std::cout << "Deleting TestPlugin" << std::endl;
}
void TestPlugin::RunEcmQuery(ignition::gazebo::EntityComponentManager &_ecm)
{
  std::cout << "Query from plugin" << std::endl;
  _ecm.EntityByComponents(components::World(), components::Joint());
}

IGNITION_ADD_PLUGIN(TestPlugin, TestPluginBase)
