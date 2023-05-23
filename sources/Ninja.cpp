#include "Ninja.hpp"
#include <sstream>

namespace ariel
{

    Ninja::Ninja(const std::string &name, const Point &location, int speed, int hitPoints)
        : Character(name, location, hitPoints >= 0 ? hitPoints : 0), speed(speed >= 0 ? speed : 0)
    {
    }

    void Ninja::slash(Character *enemy)
    {
        if (enemy == nullptr)
        {
            throw std::runtime_error("nullptr enemy!");
        }
        if (this == enemy)
        {
            throw std::runtime_error("cannot self harm!");
        }
        if (!isAlive())
        {
            throw std::runtime_error("you are in heaven already");
        }
        if (!enemy->isAlive())
        {
            throw std::runtime_error("the enemy is in heaven already");
        }
        if (this->isAlive() && this->distance(enemy) < 1)
        {
            enemy->hit(40);
        }
    }
    void Ninja::attackNC(Character *other)
    {
        if (this->distance(other) >= 1)
        {
            move(other);
        }
        else
        {
            slash(other);
        }
    }
    void Ninja::move(Character *other)
    {
        if (other == nullptr)
        {
            throw std::invalid_argument("Invalid enemy character. Cannot move towards nullptr.");
        }

        if (!isAlive())
        {
            throw std::runtime_error("Ninja is already dead.");
        }

        if (!other->isAlive())
        {
            throw std::runtime_error("Enemy character is already dead.");
        }

        double distance = this->distance(other);

        if (distance < 1)
        {
            // Ninja is already close to the enemy, no need to move
            return;
        }

        if (distance <= getspeed())
        {
            // Ninja can reach the enemy in one move
            setLocation(getLocation().moveTowards(getLocation(), other->getLocation(), distance));
        }
        else
        {
            // Ninja moves towards the enemy at its maximum speed
            setLocation(getLocation().moveTowards(getLocation(), other->getLocation(), getspeed()));
        }
    }

    int Ninja::getspeed() const
    {
        return speed;
    }
    void Ninja::setspeed(int speed)
    {
        this->speed = speed;
    }
    std::string Ninja::print() const
    {
        std::ostringstream oss;
        oss << "N " << getName() << " is at location " << getLocation().print();

        if (isAlive())
        {
            oss << ", has " << getHitPoints() << " hit points and moves at speed " << speed;
        }
        else
        {
            oss << " (";
            oss << getName() << ")"; // Print the name in parentheses if the ninja is dead
        }

        return oss.str();
    }

}