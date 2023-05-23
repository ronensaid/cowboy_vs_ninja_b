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
    class SmartTeam
    {
    private: 
        std::vector<Character *> members;
        Character *leader;



    public:
        SmartTeam(Character *_leader);
        ~SmartTeam();
        SmartTeam(const SmartTeam &other) = default;            // copy constructor
        SmartTeam &operator=(const SmartTeam &other) = default; // copy assignment operator
        SmartTeam(SmartTeam &&other) = default;                 // move constructor
        SmartTeam &operator=(SmartTeam &&other) = default;      // move assignment operator

        void add(Character *member);
        void attack(SmartTeam *enemyTeam);
        int stillAlive();
        std::string print();

        bool contains(Character *character);
        Character *getLeader();
        void sortTeam();
        void NextLeader();
        Character *DistanceBasedAttack(SmartTeam *enemy);

    };
}

#endif /* TEAM_HPP */
