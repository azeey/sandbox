#include <ignition/test_ign_cmake_visibility/Export.hh>

int test_hidden_func(int arg1, int arg2)
{
  return arg1 + arg2;
}

IGNITION_TEST_IGN_CMAKE_VISIBILITY_HIDDEN
int test_explicitly_hidden_func(int arg1, int arg2)
{
  return arg1 + arg2;
}

IGNITION_TEST_IGN_CMAKE_VISIBILITY_VISIBLE
int test_visible_func(int arg1, int arg2)
{
  return arg1 + arg2;
}
