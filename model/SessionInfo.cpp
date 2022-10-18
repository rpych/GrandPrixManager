#include "SessionInfo.hpp"
#include "Driver.hpp"

namespace gp::model
{
ASessionInfo::ASessionInfo(int startPosition/*, std::shared_ptr<ADriver> driver*/):
startPosition(startPosition),
score(0.0)
//driver(driver)
{}


//SessionInfo part
SessionInfo::SessionInfo(int startPosition/*, std::shared_ptr<ADriver> driver*/):
ASessionInfo(startPosition)
{}

void SessionInfo::updateScore(double lapScore)
{
  score += lapScore;
}

void SessionInfo::setStartingPosition(int position)
{
  startPosition = position;
}

} //gp::model