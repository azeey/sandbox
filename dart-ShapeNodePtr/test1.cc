/*
 * Copyright (C) 2021 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 3.0 (the "License");
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

#include "helpers.hh"

// This demonstrates that even though `shape1` and `shape2` should keep the
// sphere skeleton alive, reseting the `sphere` pointer causes a use-after-free
// type of memory error. This error can cause a segfault, but it's hard to
// reproduce, so using valgrind or ASAN is the best way to observe the issue.
int main(int argc, char *argv[])
{
  SkeletonPtr sphere = createSphere();

  ShapeNodePtr shape1 = sphere->getBodyNode(0)->getShapeNode(0);
  ShapeNodePtr shape2 = shape1;

  // Delete sphere first
  sphere.reset();
  return 0;
}
