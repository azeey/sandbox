protobuf_generate_cpp(PROTO_SRCS2 PROTO_HDRS2 double.proto)
add_library(test-plugin-msgs2 SHARED ${PROTO_SRCS2} ${PROTO_HDRS2})
target_include_directories(test-plugin-msgs2 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)

