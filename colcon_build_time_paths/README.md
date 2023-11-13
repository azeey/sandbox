Test if colcon can find binary installed by `project1` from a `find_program` in `project2`.

Build with

```
colcon build --packages-select project1 --event-handlers console_direct+
colcon build --packages-select project2 --event-handlers console_direct+
```


