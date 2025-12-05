#!/bin/bash
set -e

echo "Setting up Protobuf-gRPC development environment..."

# Find protoc executable
PROTOC_PATH=$(which protoc)
PROTOBUF_VERSION=$(protoc --version | cut -d' ' -f2)

echo "Found protoc at: $PROTOC_PATH"
echo "Protobuf version: $PROTOBUF_VERSION"

# Find protobuf libraries and includes
PROTOBUF_LIB_DIR=$(pkg-config --variable=libdir protobuf)
PROTOBUF_INCLUDE_DIR=$(pkg-config --variable=includedir protobuf)

echo "Protobuf library directory: $PROTOBUF_LIB_DIR"
echo "Protobuf include directory: $PROTOBUF_INCLUDE_DIR"

# Find gRPC plugin if available
GRPC_PLUGIN=$(which grpc_cpp_plugin 2>/dev/null || echo "")
if [ -n "$GRPC_PLUGIN" ]; then
    echo "Found gRPC plugin at: $GRPC_PLUGIN"
else
    echo "Warning: grpc_cpp_plugin not found in PATH"
fi

# Create a helper script to find protobuf paths
cat > /tmp/find_protobuf.sh << 'EOF'
#!/bin/bash
# Helper script to find protobuf paths
echo "PROTOBUF_PROTOC_EXECUTABLE=$(which protoc)"
echo "PROTOBUF_INCLUDE_DIR=$(pkg-config --variable=includedir protobuf)"
echo "PROTOBUF_LIBRARIES=$(pkg-config --variable=libdir protobuf)"
GRPC_PLUGIN=$(which grpc_cpp_plugin 2>/dev/null || echo "")
if [ -n "$GRPC_PLUGIN" ]; then
    echo "PROTOBUF_GRPC_PLUGIN_EXECUTABLE=$GRPC_PLUGIN"
fi
EOF

chmod +x /tmp/find_protobuf.sh

echo ""
echo "Development environment setup complete!"
echo ""
echo "To build a project, navigate to a subdirectory and run:"
echo "  mkdir -p build && cd build"
echo "  cmake .."
echo "  make"
echo ""
echo "Note: Some CMakeLists.txt files have hardcoded Windows paths."
echo "You may need to update them to use Linux paths or use find_package(Protobuf)."

