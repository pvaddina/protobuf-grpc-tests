# gRPC Client-Server Test Project

This project demonstrates a C++ gRPC client-server application with separate directories for interface definitions, client, and server.

## Project Structure

```
client-server-test1/
├── interface/          # Protobuf service definitions
│   ├── calculator.proto
│   └── CMakeLists.txt
├── server/             # gRPC server implementation
│   ├── server.cpp
│   └── CMakeLists.txt
├── client/             # gRPC client implementation
│   ├── client.cpp
│   └── CMakeLists.txt
├── CMakeLists.txt      # Main build configuration
└── README.md
```

## Prerequisites

- CMake 3.9 or higher
- C++14 compatible compiler
- Protobuf compiler (protoc)
- gRPC C++ libraries (libgrpc++-dev)
- gRPC plugin (grpc_cpp_plugin)

## Building the Project

```bash
mkdir build
cd build
cmake ..
make
```

This will generate:
- `calculator_server` - The gRPC server executable
- `calculator_client` - The gRPC client executable

## Running the Application

1. **Start the server** (in one terminal):
   ```bash
   ./calculator_server
   ```
   The server will listen on `0.0.0.0:50051`

2. **Run the client** (in another terminal):
   ```bash
   ./calculator_client
   ```

## Service Definition

The `CalculatorService` provides two RPC methods:
- `Add(AddRequest) returns (AddResponse)` - Adds two numbers
- `Multiply(MultiplyRequest) returns (MultiplyResponse)` - Multiplies two numbers

## Example Output

**Server:**
```
Server listening on 0.0.0.0:50051
Server: Add(10.5, 20.3) = 30.8
Server: Multiply(5, 4) = 20
```

**Client:**
```
Client: Add(10.5, 20.3) = 30.8
Client: Multiply(5, 4) = 20
```

