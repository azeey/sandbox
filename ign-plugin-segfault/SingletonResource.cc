#include "SingletonResource.hh"

SingletonResource *SingletonResource::Instance()
{
  static SingletonResource instance;
  return &instance;
}
void SingletonResource::Register(const std::function<void()> &cb)
{
  this->handlers.push_back(cb);
}

SingletonResource::~SingletonResource()
{
  std::cout << "Destroying SingletonResource" << std::endl;
}
