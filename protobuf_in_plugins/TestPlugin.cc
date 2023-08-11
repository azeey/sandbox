#include <cstdlib>
#include <iostream>
#include <gz/plugin/Register.hh>
#include "TestPlugin.hh"
#include "double.pb.h"

class TestPlugin: public TestPluginBase
{
  public: TestPlugin()
  {
    testplugin::Double msg;
    msg.set_data(std::rand());
    std::cout << "TestPlugin ctor " << msg.DebugString();
  }
  public: ~TestPlugin() = default;
};

GZ_ADD_PLUGIN(TestPlugin, TestPluginBase)

