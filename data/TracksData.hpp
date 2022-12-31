#pragma once
#include <memory>
#include <map>

namespace gp::model
{
  class ATrack;
  class Track;
}

namespace gp::data
{

class TracksData
{
  static std::map<std::string, model::Track> tracks;
  static std::map<std::string, model::Track> initTracksData();
public:
  static std::shared_ptr<model::ATrack> getTrack(const std::string& name);
  static std::shared_ptr<model::ATrack> getNextTrack(const std::string& name);
  static int getTracksNum() { return tracks.size(); }
  TracksData() = delete;
};

}