This example demonstrates that singletons using gz-common's SingetonT class may have unexpected behaviors when used from 
the main application and a dlopen'd shared library.

Expected result:

```

:!./example1
singleton.num in main : 100
singleton.num in hello.so : 100
singleton.num in hello.so after ++ : 101
singleton.num in main : 101
```

When running without `extern template class SingletonT<MyData>`;

```
:!./example1
singleton.num in main : 100
singleton.num in hello.so : 0
singleton.num in hello.so after ++ : 1
singleton.num in main : 100
```

Example adapted from https://stackoverflow.com/questions/8623657/multiple-instances-of-singleton-across-shared-libraries-on-linux
