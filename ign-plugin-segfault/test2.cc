#include <memory>

#include "TestPlugin.hh"

int main(int argc, char *argv[])
{
  auto plugin = std::make_shared<TestPlugin>();
  plugin->Run();
  return 0;
}
