This demonstrates an issue with object deletion in DART. 

## Steps:

Install dart
```
apt install libdart-dev  libdart-external-odelcpsolver-dev
```

Build this demo

```
mkdir build
cd build
cmake ..
make
```

Run the executables under valgrind.

```
valgrind ./good
valgrind ./test1
valgrind ./test2
```

