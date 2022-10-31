#include <algorithm>
#include "TracksData.hpp"
#include "../model/Track.hpp"
#include <iostream>

namespace gp::data
{

std::map<std::string, model::Track> TracksData::initTracksData()
{
  std::map<std::string, model::Track> tracksTmp;
  tracksTmp.emplace("Monza", model::Track("Monza", 72));
  tracksTmp.emplace("Spa", model::Track("Spa", 54));
  return tracksTmp;
}

std::map<std::string, model::Track> TracksData::tracks{initTracksData()};

std::shared_ptr<model::Track> TracksData::getTrack(const std::string& name)
{
  const auto& res = std::find_if(tracks.begin(), tracks.end(), [&name](const auto& track)
   {
     if(track.first == name) return true;
     else return false;
   });
  if(res != tracks.end())
  {
    return std::make_shared<model::Track>(model::Track((*res).second));
  }
  return std::shared_ptr<model::Track>(nullptr);
}

std::shared_ptr<model::Track> TracksData::getNextTrack(const std::string& name)
{
  if (name == "")
  {
    const std::string trackName = (*tracks.begin()).second.getName();
    return getTrack(trackName);
  }
  const auto& res = std::find_if(tracks.begin(), tracks.end(), [&name](const auto& track)
  {
     if(track.first == name) return true;
     else return false;
  });

  auto currentCopy = tracks.end();
  if(res != tracks.end() )
  {
    currentCopy = res;
    std::advance(currentCopy, 1);
  }
  if (currentCopy != tracks.end())
  { 
    return std::make_shared<model::Track>(model::Track((*currentCopy).second));
  }
  else
  { 
    const std::string trackName = (*tracks.begin()).second.getName();
    return getTrack(trackName);
  }
}

}