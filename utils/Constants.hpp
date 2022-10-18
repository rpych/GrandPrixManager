#pragma once

namespace gp::utils
{
 constexpr int    NUM_OF_DRIVERS = 20;
 constexpr int    NUM_OF_TEAMS = 10;
 constexpr int    NUM_OF_QUALI_LAPS = 15;
 constexpr int    PIT_STOP_ON_MAX_LAP_AHEAD = 4;
 constexpr double MAX_DRIVER_EXP = 1.0;
 constexpr double COND_DURATION_COEF = 0.3; //conditions unchanged by 0.3 of session duration
 constexpr double MAX_TRACK_DIFFICULTY = 0.5;
 constexpr double MAX_COND_DIFFICULTY = 0.5;

 constexpr int INVALID = 0xFFFFFFFF;
} //gp::utils