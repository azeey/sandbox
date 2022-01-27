
#include <ignition/gazebo/EntityComponentManager.hh>

class TestPluginBase
{
  public: virtual ~TestPluginBase() = default;
  public: virtual void RunEcmQuery(ignition::gazebo::EntityComponentManager &_ecm) = 0;
};

class TestPlugin: public TestPluginBase
{
 public: ~TestPlugin() override;
  public: void RunEcmQuery(ignition::gazebo::EntityComponentManager &_ecm) override;
};
