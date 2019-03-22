/*
 * Copyright (C) 2019 Open Source Robotics Foundation
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

#include <memory>
#include <dart/dart.hpp>
#include <Eigen/Geometry>

int main(int argc, char* argv[]) {

  auto world = std::make_shared<dart::simulation::World>("test");
  world->setGravity(Eigen::Vector3d::Zero());
  const double dt = 0.001;
  world->setTimeStep(dt);

  double mass = 1.0;
  const Eigen::Matrix3d I_link = Eigen::Vector3d(0.17, 0.17, 0.17).asDiagonal();

  dart::dynamics::BodyNode::Properties bodyProperties;
  bodyProperties.mInertia.setMass(mass);
  bodyProperties.mInertia.setMoment(I_link);

  dart::dynamics::SkeletonPtr skel = dart::dynamics::Skeleton::create();
  dart::dynamics::FreeJoint::Properties jointProperties;
  auto pair = skel->createJointAndBodyNodePair<dart::dynamics::FreeJoint>(
      nullptr, jointProperties, bodyProperties);

  world->addSkeleton(skel);

  // Setting  a large torque results in a translation in the y axis even
  // though the applied force is only in the x axis.
  pair.second->addExtTorque(Eigen::Vector3d(0, 0, 5000));
  pair.second->addExtForce(Eigen::Vector3d(10, 0, 0));
  for (std::size_t i = 0; i < static_cast<std::size_t>(10.0/dt); ++i) {
      world->step();
  }
  std::cout << pair.second->getWorldTransform().translation().transpose()
            << std::endl;

  return 0;
}
