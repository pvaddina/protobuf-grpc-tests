#include <iostream>

#include "dht.pb.h"

void BaseReader(const BaseMsg& m)
{
  std::cout << "ID=" << m.id() << std::endl;
  std::cout << "Name=" << m.name() << std::endl;
}

CDhtConfigCnf DhtReader(const CDhtConfigReq& m)
{
  std::cout << "ID=" << m.baseid().id() << std::endl;
  std::cout << "Name=" << m.baseid().name() << std::endl;
  std::cout << "State=" << m.state() << std::endl;
  CDhtConfigCnf c;
  c.set_result(Result::SUCCESS);
  c.set_state(OnOff::OFF);
  return c;
}

void BaseTester()
{
  std::cout << "In BaseTester ..." << std::endl;
  BaseMsg m;
  m.set_name("This is a base msg");
  BaseReader(m);
}

void DhtTester()
{
  std::cout << "In DhtTester ..." << std::endl;
  CDhtConfigReq r;
  r.mutable_baseid()->set_name("CDhtConfigReq");
  r.mutable_baseid()->set_id(437);
  r.set_state(OnOff::ON);
  CDhtConfigCnf c = DhtReader(r);
  std::cout << "Result: " << c.result() << ", state=" << c.state() << std::endl;
}

int main()
{
  BaseTester();
  std::cout << "\n\n";

  DhtTester();
  return 0;
}


