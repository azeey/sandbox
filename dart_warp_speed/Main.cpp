/*
 * Copyright (C) 2020 Open Source Robotics Foundation
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

#include <Eigen/Geometry>
#include <dart/collision/bullet/BulletCollisionDetector.hpp>
#include <dart/collision/fcl/FCLCollisionDetector.hpp>
#include <dart/collision/ode/OdeCollisionDetector.hpp>
#include <dart/constraint/ConstraintSolver.hpp>
#include <dart/dart.hpp>
#include <dart/gui/osg/osg.hpp>
#include <dart/utils/utils.hpp>
#include <memory>

int main(int argc, char* argv[]) {

  std::cout << "skel file: " << TEST_SKEL_FILE << std::endl;
  auto world = dart::utils::SkelParser::readWorld(TEST_SKEL_FILE);

  // Try different collision detectors
  // ODE
  world->getConstraintSolver()->setCollisionDetector(
        dart::collision::OdeCollisionDetector::create());
  // Bullet
  // world->getConstraintSolver()->setCollisionDetector(
  //       dart::collision::BulletCollisionDetector::create());
  // FCL
  // auto fcl = dart::collision::FCLCollisionDetector::create();
  // fcl->setPrimitiveShapeType(dart::collision::FCLCollisionDetector::PRIMITIVE);
  // world->getConstraintSolver()->setCollisionDetector(fcl);

  // Set the friction coefficient for the floor and the ball here. I don't know
  // if there's a way to do it in the skel string.
  auto setFrictionCoeffs = [&](dart::dynamics::BodyNode *bn, double _coef)
  {
    for (auto *sn : bn->getShapeNodesWith<dart::dynamics::DynamicsAspect>())
    {
      std::cout << "Setting friction for " << sn->getName() << std::endl;
      auto *aspect = sn->getDynamicsAspect();
      aspect->setFrictionCoeff(_coef);
      aspect->setSecondaryFrictionCoeff(_coef);
    }
  };
  setFrictionCoeffs(
      world->getSkeleton("ground")->getBodyNode("ground_body"), 1.0);
  setFrictionCoeffs(world->getSkeleton("ball")->getBodyNode("ball_body"), 0.2);

  // Wrap a WorldNode around it
  ::osg::ref_ptr<dart::gui::osg::RealTimeWorldNode> node
      = new dart::gui::osg::RealTimeWorldNode(world);

  // Create a Viewer and set it up with the WorldNode
  auto viewer = dart::gui::osg::Viewer();
  viewer.addWorldNode(node);

  std::cout << viewer.getInstructions() << std::endl;

  // Set up the window to be 640x480
  viewer.setUpViewInWindow(0, 0, 640, 480);

  // Adjust the viewpoint of the Viewer
  viewer.getCameraManipulator()->setHomePosition(
      ::osg::Vec3d(-30, 0.0, 5),
      ::osg::Vec3d(0.0, 0.0, 0.0),
      ::osg::Vec3d(0.0, 0.0, 1.0));

  // We need to re-dirty the CameraManipulator by passing it into the viewer
  // again, so that the viewer knows to update its HomePosition setting
  viewer.setCameraManipulator(viewer.getCameraManipulator());

  const auto *ballBn = world->getSkeleton("ball")->getBodyNode("ball_body");
  viewer.simulate(true);
  // Begin running the application loop
  while(!viewer.done())
  {
    viewer.frame();
    if (viewer.isSimulating())
    {
      std::cout << "ball accel: " << ballBn->getLinearAcceleration().transpose()
        << std::endl;
    }
  }

  return 0;
}
