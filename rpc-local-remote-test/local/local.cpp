#pragma once

#include "dht.grpc.pb.h"

class DhtService final : public DhtConfigHandler::Service
{
public:
  ::grpc::Status Config(::grpc::ServerContext* context, const ::CDhtConfigReq* request, ::CDhtConfigCnf* response) override
  {
    return ::grpc::Status::OK;
  }
};

