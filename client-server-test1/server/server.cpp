#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "calculator.pb.h"
#include "calculator.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using calculator::CalculatorService;
using calculator::AddRequest;
using calculator::AddResponse;
using calculator::MultiplyRequest;
using calculator::MultiplyResponse;

// Implementation of the CalculatorService
class CalculatorServiceImpl final : public CalculatorService::Service {
 public:
  // Implementation of Add RPC
  Status Add(ServerContext* context, const AddRequest* request,
             AddResponse* reply) override {
    double a = request->a();
    double b = request->b();
    double result = a + b;
    
    reply->set_result(result);
    std::cout << "Server: Add(" << a << ", " << b << ") = " << result << std::endl;
    
    return Status::OK;
  }

  // Implementation of Multiply RPC
  Status Multiply(ServerContext* context, const MultiplyRequest* request,
                  MultiplyResponse* reply) override {
    double a = request->a();
    double b = request->b();
    double result = a * b;
    
    reply->set_result(result);
    std::cout << "Server: Multiply(" << a << ", " << b << ") = " << result << std::endl;
    
    return Status::OK;
  }
};

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  CalculatorServiceImpl service;

  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();
  return 0;
}

