This Example code is meant to reproduce an issue where a simple node uses 100% of CPU after about 2 minutes of run time.

To build:
```
# First source your ROS setup.*sh (eg. source /opt/ros/melodic/setup.bash)
mkdir build
cd build
cmake ..
make
./ros_high_cpu_node

```

When the node starts, it takes less 5% CPU, but after about 2 minutes, it'll go up to 100%. The fix seems to be to create a `ros::NodeHandle` that stays alive for the duration of the node. 
The timer is only there to print out the current time every second. Removing it does not change the observed behavior.

