#include "Team2.hpp"
#include "Team.hpp"
#include <math.h>
#include <sstream>

using namespace std;
namespace ariel
{
    Team2::Team2(Character *_leader) : Team(_leader)
    {
    }

    void Team2::add(Character *member)
    {
        if (members.size() >= 10)
        {
            throw std::runtime_error("Maximum limit of team members reached. Cannot add more members.");
        }
        if (member->getin())
        {
            throw std::runtime_error("Character is already a member of another team.");
        }
        members.push_back(member);
        member->setin(true);
    }

}
