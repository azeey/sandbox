#include <ignition/plugin/Loader.hh>
#include "TestPlugin.hh"

int main(int argc, char *argv[])
{
  ignition::plugin::Loader loader;
  auto pluginNames = loader.LoadLib(PLUGIN_LIB_PATH);
  auto plugin = loader.Factory<TestPluginBase>(*pluginNames.begin());

  plugin->Run();
  return 0;
}
