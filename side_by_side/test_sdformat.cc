#include <iostream>

extern "C" void cmdCheck(const char *_path);
extern "C" char *ignitionVersion();

int main(int argc, char *argv[])
{
  std::cout << "Test" << std::endl;
  std::cout << ignitionVersion << std::endl;
  cmdCheck(argv[1]);
  return 0;
}
