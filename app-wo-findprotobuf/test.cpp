#include <iostream>

#include "base.pb.h"
#include "dht.pb.h"

void BaseReader(const Base::BaseMsg& m)
{
  std::cout << "ID=" << m.id() << std::endl;
  std::cout << "Name=" << m.name() << std::endl;
}

CDhtConfigCnf DhtReader(const CDhtConfigReq& m)
{
  std::cout << "ID=" << m.baseid.id() << std::endl;
  std::cout << "Name=" << m.baseid.name() << std::endl;
  std::cout << "State=" << m.state() << std::endl;
  CDhtConfigCnf c;
  c.set_result(Result::SUCCESS);
  c.set_state(OnOff::OFF);
  return c;
}

void BaseTester()
{
  Base::BaseMsg m;
  m.set_name("This is a base msg");
  BaseReader(m);
}

void DhtTester()
{
  CDhtConfigReq r;
  r.baseid.set_name("CDhtConfigReq");
  r.baseid.set_id(437);
  r.set_state(OnOff::ON);
  CDhtConfigCnf c = DhtReader(r);
  std::cout << "Result: " << c.result() << ", state=" << c.state() << std::endl;
}

int main()
{
  BaseTester();
  return 0;
}


