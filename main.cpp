#include <iostream>
#include <memory>
#include "simulator/GrandPrix.hpp"
#include "viewer/Viewer.hpp"



int main()
{
  gp::viewer::Viewer viewer;
  viewer.run();

  std::cout<<"### Thank you for using GrandPrixManager! Bye :) ###"<<std::endl;
  return 0;  
}

