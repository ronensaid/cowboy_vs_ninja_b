#include "Character.hpp"

namespace ariel
{

    Character::Character() : name(""), location(Point(0, 0)), hitPoints(0), isin(false) {}
    Character::Character(const std::string &name, const Point &location, int hitPoints) : name(name), location(location), hitPoints(hitPoints), isin(false) {}

    bool Character::isAlive() const
    {
        if(this->hitPoints>0)
        {
            return true; 
        }
        return false;
    }

    double Character::distance(const Character *other) const
    {
        return location.distance(other->getLocation());
    }

    void Character::hit(int damage)
    {
        if (damage < 0)
        {
            throw std::invalid_argument("Cannot perform hit. Damage must be positive.");
        }
        this->hitPoints -= damage;

    }
    bool Character::getLeader()
    {
        return isLeader;
    }

    void Character::setLeader(bool isLeader)
    {
        this->isLeader = isLeader;
    }
    std::string Character::getName() const
    {
        return name;
    }

    Point Character::getLocation() const
    {
        return location;
    }
    void Character::setin(bool in)
    {
        isin = in;
    }
    bool Character::getin()
    {
        return isin;
    }
    void Character::setName(const std::string &newName)
    {
        name = newName;
    }

    void Character::setLocation(const Point &newLocation)
    {
        location = newLocation;
    }

    int Character::getHitPoints() const
    {
        return hitPoints;
    }

    void Character::setHitPoints(int newHitPoints)
    {
        hitPoints = newHitPoints;
    }

    std::string Character::print() const
    {
        std::string status = isAlive() ? "" : "(dead)";
        return name + " HP: " + std::to_string(hitPoints) + " Location: " + location.print() + " " + status;
    }
}