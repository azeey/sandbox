This tests if multiple versions of ignition libraries can be linked by the same app.

# Test Ignition Transport
Build and run `./test_transport`. With both transport6 and transport7 linked, this crashes.

# Test sdformat
Build and run `./test_sdformat ../empty.sdf`. With both libsdformat6 and libsdformat8 linked, this seems to work fine.
