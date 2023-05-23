#include "SmartTeam.hpp"
#include <math.h>
#include <vector>
#include <sstream>

using namespace std;
namespace ariel
{

    SmartTeam::SmartTeam(Character *_leader) : leader(_leader)
    {
        add(_leader);
    }

    SmartTeam::~SmartTeam()
    {
        for (Character *member : members)
        {
            delete member;
        }
    }

    void SmartTeam::add(Character *member)
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
    void SmartTeam::sortTeam()
    {
        std::vector<Character *> temp;
        for (Character *c : members)
        {
            if (Cowboy *cow = dynamic_cast<Cowboy *>(c))
            {
                temp.push_back(c);
            }
        }
        for (Character *c : members)
        {
            if (Ninja *nin = dynamic_cast<Ninja *>(c))
            {
                temp.push_back(c);
            }
        }
        this->members = temp;
    }

    void SmartTeam::attack(SmartTeam *other)
    {
        if (other == nullptr)
        {
            throw invalid_argument("the enemy team is null");
        }
        if (!other->stillAlive())
        {
            throw runtime_error("team is died");
        }
        if (!stillAlive())
        {
            throw runtime_error("team is died22");
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

    bool SmartTeam::contains(Character *character)
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

    Character *SmartTeam::getLeader()
    {
        return leader;
    }

    void SmartTeam::NextLeader()
    {
        Character *newLeader = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (Character *c : members)
        {
            if (c->isAlive() && c != leader) // Exclude the current leader from consideration
            {
                double currentDistance = leader->distance(c);
                if (currentDistance < minDistance)
                {
                    minDistance = currentDistance;
                    newLeader = c;
                }
            }
        }

        if (newLeader != nullptr)
        {
            leader = newLeader;
        }
    }
    
    Character *SmartTeam::DistanceBasedAttack(SmartTeam *enemy)
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

    int SmartTeam::stillAlive()
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

    std::string SmartTeam::print()
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


