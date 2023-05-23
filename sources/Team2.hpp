#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Team.hpp"
#include <vector>
#include <string>

namespace ariel
{
    class Team2 : public Team
    {
    public:
        Team2(Character *_leader);

        void add(Character *member);
    };
}

#endif
