The demonstrates the problem with using ign-gazebo's EntityComponentManager in 
plugins. As I understand it, when a plugin makes a query using the 
EntityComponentManager (eg. `EntityComponentManager::Each`, or 
`EntityComponentManager::EntityByComponents`), `EntityComponentManager` creates 
a view for those queries. But since these functions are templates, the code
generated for these queries lives in the shared library of the plugin. When
creating the views, objects of type `detail::View<...>` are created and stored
in a container in `EntityComponentManagerPrivate`. These `View` objects have
their virtual destructors in the shared library.

If the plugin's shared library is unloaded before the `EntityComponentManager`
object is destructed, the virtual destructors for the `View` objects stored in
the `EntityComponentManagerPrivate` will dangle. Subsequently, trying to
destruct `EntityComponentManager` will lead to a segfault because the
destructor ultimately will try to access the virtual destructors of the `View`
objects. The problem currently arises when the ign-gazebo-gui exits, but it
could happen in other situations.

In this example code, the sequence of destroying the `EntityComponentManager`
followed by unloading the plugin shared library works fine, but the reverse
causes a segfault.


## To run


Assuming ign-gazebo6 is installed,

``` 
cmake -S . -B build
cmake --build build
build/ecm_from_shared_lib

```

