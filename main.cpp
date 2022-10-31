#include <iostream>
#include <memory>
#include "simulator/GrandPrix.hpp"
#include "viewer/Viewer.hpp"



int main()
{
  //auto grandPrix = std::make_shared<gp::simulator::GrandPrix>();
  //grandPrix->prepare();
  gp::viewer::Viewer viewer;
  viewer.run();

  std::cout<<"Hello from GrandPrixManager"<<std::endl;
  return 0;  
}

