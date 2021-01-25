#include <memory>
#include <vector>

#include <Eigen/Geometry>
#include <Eigen/Dense>

#include "dart/math/Geometry.hpp"
#include "dart/dynamics/GenericJoint.hpp"
#include "dart/dynamics/FreeJoint.hpp"
#include "dart/simulation/World.hpp"

using namespace dart::math;
using namespace dart::collision;
using namespace dart::dynamics;
using namespace dart::simulation;

//==============================================================================
// createObject and createSphere adapted from dart/unittests/TestHelpers.hpp
SkeletonPtr createObject()
{
  GenericJoint<SE3Space>::Properties joint(std::string("joint1"));

  BodyNode::Properties node(BodyNode::AspectProperties(std::string("link1")));

  SkeletonPtr skeleton = Skeleton::create();
  skeleton->createJointAndBodyNodePair<FreeJoint>(nullptr, joint, node);

  return skeleton;
}

SkeletonPtr createSphere()
{
  SkeletonPtr sphere = createObject();

  BodyNode *bn = sphere->getBodyNode(0);
  std::shared_ptr<EllipsoidShape> ellipShape(
      new EllipsoidShape(Eigen::Vector3d::Constant(2.0)));
  bn->createShapeNodeWith<VisualAspect, CollisionAspect, DynamicsAspect>(
      ellipShape);

  return sphere;
}


