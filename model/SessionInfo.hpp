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
    ASessionInfo(int startPosition);
  public:
    virtual ~ASessionInfo() {}
    int getStartPosition() { return startPosition; }
    double getScore() { return score; }
    virtual void updateScore(double lapScore) = 0;
    virtual void setStartingPosition(int position) = 0;
  };

  class SessionInfo: public ASessionInfo
  {
  public:
    SessionInfo(int startPosition);
    virtual ~SessionInfo() {}
    virtual void updateScore(double lapScore) override;
    virtual void setStartingPosition(int position) override;
  };
} //gp::model