#include "Track.hpp"

namespace gp::model
{

Track::Track(const Track& track): ATrack(std::string(track.name), track.laps)
{}

}