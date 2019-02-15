This is an example that demonstrates a segfault that occurs at the end of a program that uses ign-plugin.
There are three components to this example:

* `SingletonResource`: This is a singleton class that stores a vector of `std::function` objects. It's linked in as a shared library so the singleton is truly a singleton and there is only one instance of it.
* `TestPlugin`: This is a class that gets an instance of the singleton and registers a callback function. This class can be loaded as a plugin or instantiated directly.
* `test1.cc` and `test2.cc`
    * These are driver applications that load/instantiate `TestPlugin`. `test1.cc` loads `TestPlugin` as a plugin and is the one that gets a segfault. `test2.cc` instantiates the `TestPlugin` class directly and no segfault occurs


# Building

This example requires the `ignition-plugin` library. The segfault only occurs when built with clang so here's an example build command

```
CC=clang CXX=clang++ cmake . -Bbuild
cmake --build build
```

# Running

```
build/test1
build/test2
```

