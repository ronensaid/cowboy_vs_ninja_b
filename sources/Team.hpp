#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include <vector>
#include <unordered_set>
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

namespace ariel
{
    class Team
    {
    protected:
        std::vector<Character *> members;
        Character *leader;



    public:
        Team(Character *_leader);
        ~Team();
        Team(const Team &other) = default;            // copy constructor
        Team &operator=(const Team &other) = default; // copy assignment operator
        Team(Team &&other) = default;                 // move constructor
        Team &operator=(Team &&other) = default;      // move assignment operator

        void add(Character *member);
        void attack(Team *enemyTeam);
        int stillAlive();
        std::string print();

        bool contains(Character *character);
        Character *getLeader();
        void sortTeam();
        void NextLeader();
        Character *DistanceBasedAttack(Team *enemy);

    };
}

#endif /* TEAM_HPP */
