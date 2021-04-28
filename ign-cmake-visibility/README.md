This demonstrates that ign-cmake does not hide symbols by default.

After building, use `nm -C lib/libtset_ign_cmake_visibility.so | grep test_` to see which symbols are hidden:

```
 nm -C lib/libtest_ign_cmake_visibility.so | grep test_
00000000000005c0 T test_hidden_func(int, int)
00000000000005e0 T test_visible_func(int, int)
00000000000005d0 t test_explicitly_hidden_func(int, int)
```

`test_hidden_func` should be hidden by default, but as the `T` (global symbol) in the `nm` output shows, it is visibile.
