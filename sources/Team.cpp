#include "Team.hpp"
#include <math.h>
#include <vector>
#include <sstream>

using namespace std;
namespace ariel
{

    Team::Team(Character *_leader) : leader(_leader)
    {
        add(_leader);
    }

    Team::~Team()
    {
        for (Character *member : members)
        {
            delete member;
        }
    }

    void Team::add(Character *member)
    {
        if (member->getin())
        {
            throw std::runtime_error("Character is already a member of another team.");
        }
        if (members.size() >= 10)
        {
            throw std::runtime_error("Maximum limit of team members reached. Cannot add more members.");
        }
        if (member->isAlive() && member->getin() == false)
        {
            members.push_back(member);
            member->setin(true);
            sortTeam();
        }
    }
    void Team::sortTeam()
    {
        std::sort(members.begin(), members.end(), [](Character *a, Character *b)
                  {
        Cowboy *cboy1 = dynamic_cast<Cowboy *>(a);
        Cowboy *cboy2 = dynamic_cast<Cowboy *>(b);
        if (cboy1 && !cboy2) {
            return true;
        }
        if (!cboy1 && cboy2) {
            return false;
        }
        return false; });
    }

    void Team::attack(Team *other)
    {
        if (other == nullptr)
        {
            throw invalid_argument("nullptr enemy team!");
        }
        if (!other->stillAlive())
        {
            throw runtime_error("the other team is having a party in heaven");
        }
        if (!stillAlive())
        {
            throw runtime_error("your team is having a party in heaven");
        }
        if (!this->leader->isAlive())
        {
            NextLeader();
        }

        Character *target = DistanceBasedAttack(other);
        for (Character *member : members)
        {
            if (!target->isAlive() && member->isAlive())
            {
                if (!other->stillAlive())
                {
                    return;
                }
                target = DistanceBasedAttack(other);
                member->attackNC(target);
            }
            else if (target->isAlive() && member->isAlive())
            {
                member->attackNC(target);
            }
        }
    }

    bool Team::contains(Character *character)
    {
        // Check if the character is the leader of the team
        if (leader == character)
        {
            return true;
        }

        // Check if the character is a member of the team
        for (auto member : members)
        {
            if (member == character)
            {
                return true;
            }
        }

        // The character is not in the team
        return false;
    }

    Character *Team::getLeader()
    {
        return leader;
    }

    void Team::NextLeader()
    {
        Character *newLeader = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (Character *member : members)
        {
            if (member->isAlive() && member != leader) // Exclude the current leader from consideration
            {
                double currentDistance = leader->distance(member);
                if (currentDistance < minDistance)
                {
                    minDistance = currentDistance;
                    newLeader = member;
                }
            }
        }

        if (newLeader != nullptr)
        {
            leader = newLeader;
        }
    }

    Character *Team::DistanceBasedAttack(Team *enemy)
    {
        if (enemy->stillAlive() < 1)
        {
            throw std::runtime_error("the team is dead");
        }

        double minDistance = std::numeric_limits<double>::max();
        Character *closestEnemy = nullptr;

        for (Character *enemyMember : enemy->members)
        {
            if (enemyMember->isAlive())
            {
                double distance = leader->distance(enemyMember);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    closestEnemy = enemyMember;
                }
            }
        }

        return closestEnemy;
    }

    int Team::stillAlive()
    {
        int count = 0;
        for (Character *member : members)
        {
            if (member->isAlive())
            {
                count++;
            }
        }
        return count;
    }

    std::string Team::print()
    {
        std::ostringstream oss;
        oss << "Team:" << std::endl;
        for (Character *member : members)
        {
            oss << member->print() << std::endl;
        }
        return oss.str();
    }
}
