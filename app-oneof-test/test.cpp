#include <iostream>

#include "base.pb.h"

void BaseTester()
{
  std::cout << "In BaseTester ..." << std::endl;

  CHomeAutoParams m;
  m.set_homeaddress("My home address");
}

int main()
{
  BaseTester();
  return 0;
}


