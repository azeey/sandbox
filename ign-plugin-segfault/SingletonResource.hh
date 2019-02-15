#pragma once

#include <functional>
#include <iostream>
#include <vector>

class SingletonResource
{
  public: static SingletonResource *Instance();
  public: void Register(const std::function<void()> &cb);

  public: ~SingletonResource();

  public: SingletonResource(const SingletonResource &) = delete;
  public: void operator=(const SingletonResource &) = delete;

  private: SingletonResource() = default;
  private: std::vector<std::function<void()>> handlers;
};
