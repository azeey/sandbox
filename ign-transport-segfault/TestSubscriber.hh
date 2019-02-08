#pragma once

#include <thread>
#include <iostream>
#include <ignition/transport/Node.hh>

class TestSubscriberBase
{
  public:
  virtual ~TestSubscriberBase() = default;

  public:
  virtual void Run() = 0;
};

class TestSubscriber : public TestSubscriberBase
{
  public:
  void Callback(const ignition::msgs::Int32 &)
  {
    std::lock_guard<std::mutex> lk(this->cbMutex);
    this->gotMessage = true;
    this->cbCondition.notify_all();
  }

  public:
  void Run() override
  {
    std::cout << "Starting Runner" << std::endl;
    ignition::transport::Node node;
    node.Subscribe("/data", &TestSubscriber::Callback, this);
    std::unique_lock<std::mutex> lk(this->cbMutex);
    this->cbCondition.wait(lk, [this] { return this->gotMessage; });
    std::cout << "Runner Finished" << std::endl;
  }

  private: bool gotMessage = false;
  private: std::mutex cbMutex;
  private: std::condition_variable cbCondition;
};
