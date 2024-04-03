Demonstrates that when using `ament_environment_hooks`, `.dsv` files not processed properly unless there is a `.sh` file with the same name registered with `ament_environment_hooks`. This `.sh` file can be an empty file.

The issue appears to be with `ament_package` since building this package with `colcon` doesn't exhibit the same problem.

So, to test this, you'll need to build it using `cmake` and install it into `/opt/ros/<distro>`.

Using `iron` as `<distro>`:

```
source /opt/ros/iron/setup.bash
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/opt/ros/iron
make
sudo make install

```

Then, source `setup.bash` again and check if the `HAVE_TEST_HOOK` environment is set:

```

source /opt/ros/iron/setup.bash
echo $HAVE_TEST_HOOK
```

Next, uncomment the `ament_environment_hooks` in the `CMakeLists.txt` and do:

```
make
sudo make install
source /opt/ros/iron/setup.bash
echo $HAVE_TEST_HOOK

```
It should output "It worked!"
