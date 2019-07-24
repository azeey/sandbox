#include <ros/ros.h>

class TestNode {
  public:
    TestNode() {
      ros::NodeHandle pnh("~");

      ros::Time t_init = ros::Time::now();
      timer_ =
          pnh.createTimer(ros::Duration(1.0), [=](const ros::TimerEvent &ev) {
            std::cout << ev.current_real - t_init << std::endl;
          });

      double x;
      pnh.getParam("some_param", x);
      std::cout << "x: " << x << std::endl;
    };

  private:
    ros::Timer timer_;
};

int main(int argc, char **argv) {
  ros::init(argc, argv, "test_node");

  // Uncomment the following to "fix" the problem
  // ros::NodeHandle nh;
  TestNode node;

  ros::spin();

  return 0;
}
