#include <iostream>
#include "simulator/GrandPrix.hpp"



int main()
{
  gp::simulator::GrandPrix grandPrix;
  grandPrix.prepare();

  std::cout<<"Hello from GrandPrixManager"<<std::endl;
  return 0;  
}

