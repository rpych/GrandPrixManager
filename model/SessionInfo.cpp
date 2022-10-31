#include "SessionInfo.hpp"
#include "Driver.hpp"

namespace gp::model
{
ASessionInfo::ASessionInfo(int startPosition):
startPosition(startPosition),
score(0.0)
{}


//SessionInfo part
SessionInfo::SessionInfo(int startPosition):
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