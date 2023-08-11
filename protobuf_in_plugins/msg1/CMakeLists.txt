protobuf_generate_cpp(PROTO_SRCS1 PROTO_HDRS1 double.proto)
add_library(test-plugin-msgs1 SHARED ${PROTO_SRCS1} ${PROTO_HDRS1})
target_include_directories(test-plugin-msgs1 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)
