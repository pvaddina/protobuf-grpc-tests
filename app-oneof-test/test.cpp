#include <iostream>

#include "base.pb.h"

void Process(CHomeAutoParams& msg)
{
  if (msg.has_shades())
  {
    std::cout << "How far are the shades open = " << msg.shades().currentopenpercentage() << std::endl;
  }
}

void BaseTester()
{
  std::cout << "In BaseTester ..." << std::endl;

  CHomeAutoParams m;

  CShadesCtrl* sc = m.mutable_shades();
  sc->set_state(OpenUpto::OPEN);
  sc->set_currentopenpercentage(34);

  Process(m);
}

int main()
{
  BaseTester();
  return 0;
}


