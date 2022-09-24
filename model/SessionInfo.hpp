#pragma once
#include <memory>
#include "Driver.hpp"

//class ADriver;
namespace gp::model
{
  class ASessionInfo
  {
  protected:
    int startPosition;
    double score;
    //std::shared_ptr<ADriver> driver;
    ASessionInfo(int startPosition/*, std::shared_ptr<ADriver> driver*/);
  public:
    int getStartPosition() { return startPosition; }
    double getScore() { return score; }
    //std::shared_ptr<ADriver> getDriver() { return driver; }
    virtual void updateScore(double lapScore) = 0;
  };

  class SessionInfo: public ASessionInfo
  {
  public:
    SessionInfo(int startPosition/*, std::shared_ptr<ADriver> driver*/);
    virtual void updateScore(double lapScore);
  };
} //gp::model