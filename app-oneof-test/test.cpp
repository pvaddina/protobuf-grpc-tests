#include <iostream>

#include "base.pb.h"

void Process(CHomeAutoParams& msg)
{
  if (msg.has_shades())
  {
    std::cout << "How far are the shades open = " << msg.shades().currentopenpercentage() << std::endl;
  }
  else if (msg.has_lighting())
  {
    std::cout << "Living room=" << msg.lighting().livingroom() << ", Bedroom=" << msg.lighting().bedroom() << ", Kitchen=" << msg.lighting().kitchenroom() << std::endl;
  }
  else if (msg.has_heating())
  {
    std::cout << "Name=" << msg.heating().name() << ", CurrentTemp=" << msg.heating().currenttemp() << ", DesiredTemp=" << msg.heating().desiredtemp() << std::endl;
  }
}

void SetShades(CHomeAutoParams& m)
{
  CShadesCtrl* sc = m.mutable_shades();
  sc->set_state(OpenUpto::OPEN);
  sc->set_currentopenpercentage(34);
}

void SetLighting(CHomeAutoParams& m)
{
  CLightingCtrl* lc = m.mutable_lighting();
  lc->set_livingroom(LightOnOff::ON);
  lc->set_bedroom(LightOnOff::ON);
  lc->set_kitchenroom(LightOnOff::OFF);
}

void SetHeating(CHomeAutoParams& m)
{
  CHeatingCtrl* hc = m.mutable_heating();
  hc->set_name("Automated heating control");
  hc->set_currenttemp(32.445);
  hc->set_desiredtemp(55.32);
}

void BaseTester()
{
  std::cout << "In BaseTester ..." << std::endl;

  CHomeAutoParams m;

  SetShades(m);
  Process(m);

  SetHeating(m);
  Process(m);

  SetLighting(m);
  Process(m);
}

int main()
{
  BaseTester();
  return 0;
}


