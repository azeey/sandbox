/*
 * Copyright (C) 2022 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <ignition/gazebo/EntityComponentManager.hh>
#include <ignition/gazebo/components/Link.hh>
#include <ignition/gazebo/components/Model.hh>
#include <ignition/plugin/Loader.hh>
#include <iostream>

#include "TestPlugin.hh"

using namespace ignition;
using namespace gazebo;
using namespace components;

//////////////////////////////////////////////////
int main(int argc, char **argv)
{
  std::shared_ptr<TestPluginBase> plugin;
  {
    ignition::plugin::Loader loader;
    auto pluginNames = loader.LoadLib(PLUGIN_LIB_PATH);
    plugin = loader.Factory<TestPluginBase>(*pluginNames.begin());
    if (!plugin)
    {
      std::cout << "Plugin not found"  << std::endl;
    }
    else
    {
      std::cout << "Loaded: " << PLUGIN_LIB_PATH  << std::endl;
    }
  }
  auto ecm = std::make_unique<EntityComponentManager>();
  plugin->RunEcmQuery(*ecm);


  // This sequence of resets/destructions does not cause a crash
  // ecm.reset();
  // plugin.reset();

  // This sequence of resets/destructions causes a crash because the plugin is 
  // unloaded before the views in the ECMare destructed
  plugin.reset();
  ecm.reset();
}
