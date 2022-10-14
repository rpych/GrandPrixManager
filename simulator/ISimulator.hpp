#pragma once

class ISimulator
{
public:
  virtual void simulate() = 0;
  virtual ~ISimulator() {}
};