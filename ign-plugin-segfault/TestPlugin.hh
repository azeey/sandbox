#pragma once

#include <functional>
#include <iostream>
#include <vector>

#include "SingletonResource.hh"

class TestPluginBase
{
  public:
  virtual ~TestPluginBase() = default;

  public:
  virtual void Run() = 0;
};

class TestPlugin : public TestPluginBase
{
  public:
  void Callback()
  {
  }

  public:
  void Run() override
  {
    std::cout << "Starting Runner" << std::endl;
    auto singleton = SingletonResource::Instance();
    singleton->Register(std::bind(&TestPlugin::Callback, this));
    std::cout << "Runner Finished" << std::endl;
  }
};
