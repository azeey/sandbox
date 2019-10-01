#include <iostream>

extern "C" void cmdTopicList();

int main(int argc, char *argv[])
{
  std::cout << "Test" << std::endl;
  cmdTopicList();
  return 0;
}
