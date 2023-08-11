/*
 * Copyright (C) 2023 Open Source Robotics Foundation
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

#include <gz/plugin/Loader.hh>
#include <iostream>

#include "TestPlugin.hh"

//////////////////////////////////////////////////
int main(int argc, char **argv)
{
  std::shared_ptr<TestPluginBase> plugin1;
  {
    gz::plugin::Loader loader;
    auto pluginNames = loader.LoadLib(PLUGIN_LIB_PATH1);
    plugin1 = loader.Factory<TestPluginBase>(*pluginNames.begin());
    if (!plugin1)
    {
      std::cout << "Plugin not found"  << std::endl;
    }
    else
    {
      std::cout << "Loaded: " << PLUGIN_LIB_PATH1  << std::endl;
    }
  }
  std::shared_ptr<TestPluginBase> plugin2;
  {
    gz::plugin::Loader loader;
    auto pluginNames = loader.LoadLib(PLUGIN_LIB_PATH2);
    plugin2 = loader.Factory<TestPluginBase>(*pluginNames.begin());
    if (!plugin2)
    {
      std::cout << "Plugin not found"  << std::endl;
    }
    else
    {
      std::cout << "Loaded: " << PLUGIN_LIB_PATH2  << std::endl;
    }
  }
}

