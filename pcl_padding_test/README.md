*Credit goes to @ntfshard for original code*

This code shows that the absence of padding bytes in `sensor_msgs::msg::PointCloud2` messages is handled properly by PCL when converting to `PCL::PointCloud<T>` data types. This was discussed as part of https://github.com/gazebosim/gz-sensors/pull/493


A sample run outputs:

```
header: seq: 0 stamp: 0 frame_id:

points[]: 2
width: 2
height: 1
is_dense: 1
sensor origin (xyz): [0, 0, 0] / orientation (xyzw): [0, 0, 0, 1]

Message Debug:{header: {stamp: {sec: 0, nanosec: 0}, frame_id: ""}, height: 1, width: 2, fields: [{name: "x", offset: 0, datatype: 6, count: 1}, {name: "y", offset: 4, datatype: 6, count: 1}, {name: "intensity", offset: 8, datatype: 2, count: 1}, {name: "z", offset: 12, datatype: 6, count: 1}], is_bigendian: false, point_step: 16, row_step: 32, data: [10, 0, 0, 0, 20, 0, 0, 0, 40, 0, 0, 0, 30, 0, 0, 0, 11, 0, 0, 0, 21, 0, 0, 0, 41, 0, 0, 0, 31, 0, 0, 0], is_dense: true}
Data size:32
Serialized Message size:169
Point step:16
Converted PCL Point Cloud:
x: 10, y: 20, z: 30, intensity: 40
x: 11, y: 21, z: 31, intensity: 41
Converted PCL Point Cloud2:
x: 10, y: 20, z: 30, intensity: 40
x: 11, y: 21, z: 31, intensity: 41


Message Debug:{header: {stamp: {sec: 0, nanosec: 0}, frame_id: ""}, height: 1, width: 2, fields: [{name: "x", offset: 0, datatype: 6, count: 1}, {name: "y", offset: 4, datatype: 6, count: 1}, {name: "intensity", offset: 8, datatype: 2, count: 1}, {name: "z", offset: 9, datatype: 6, count: 1}], is_bigendian: false, point_step: 13, row_step: 26, data: [10, 0, 0, 0, 20, 0, 0, 0, 40, 30, 0, 0, 0, 11, 0, 0, 0, 21, 0, 0, 0, 41, 31, 0, 0, 0], is_dense: true}
Data size:26
Serialized Message size:163
Point step:13
Converted PCL Point Cloud:
x: 10, y: 20, z: 30, intensity: 40
x: 11, y: 21, z: 31, intensity: 41
Converted PCL Point Cloud2:
x: 10, y: 20, z: 30, intensity: 40
x: 11, y: 21, z: 31, intensity: 41

```
