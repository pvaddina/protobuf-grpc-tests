#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "calculator.pb.h"
#include "calculator.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using calculator::CalculatorService;
using calculator::AddRequest;
using calculator::AddResponse;
using calculator::MultiplyRequest;
using calculator::MultiplyResponse;

class CalculatorClient {
 public:
  CalculatorClient(std::shared_ptr<Channel> channel)
      : stub_(CalculatorService::NewStub(channel)) {}

  // Calls the Add RPC
  double Add(double a, double b) {
    // Data we are sending to the server.
    AddRequest request;
    request.set_a(a);
    request.set_b(b);

    // Container for the data we expect from the server.
    AddResponse reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    Status status = stub_->Add(&context, request, &reply);

    // Act upon its status.
    if (status.ok()) {
      return reply.result();
    } else {
      std::cout << "RPC failed: " << status.error_message() << std::endl;
      return -1;
    }
  }

  // Calls the Multiply RPC
  double Multiply(double a, double b) {
    MultiplyRequest request;
    request.set_a(a);
    request.set_b(b);

    MultiplyResponse reply;
    ClientContext context;

    Status status = stub_->Multiply(&context, request, &reply);

    if (status.ok()) {
      return reply.result();
    } else {
      std::cout << "RPC failed: " << status.error_message() << std::endl;
      return -1;
    }
  }

 private:
  std::unique_ptr<CalculatorService::Stub> stub_;
};

int main(int argc, char** argv) {
  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint (in this case,
  // localhost at port 50051). We indicate that the channel isn't authenticated
  // (use of InsecureChannelCredentials()).
  std::string target_str = "localhost:50051";
  
  CalculatorClient client(
      grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));

  // Test the Add RPC
  double a = 10.5;
  double b = 20.3;
  double result = client.Add(a, b);
  std::cout << "Client: Add(" << a << ", " << b << ") = " << result << std::endl;

  // Test the Multiply RPC
  double c = 5.0;
  double d = 4.0;
  result = client.Multiply(c, d);
  std::cout << "Client: Multiply(" << c << ", " << d << ") = " << result << std::endl;

  return 0;
}

