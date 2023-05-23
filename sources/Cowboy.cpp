#include "Cowboy.hpp"
#include <sstream>
namespace ariel
{
    Cowboy::Cowboy(std::string name, Point location)
        : Character(name, location, 110), bullets(6) {}

    void Cowboy::shoot(Character *enemy)
    {
        if (enemy == this)
        {
            throw std::runtime_error("Cannot shoot yourself.");
        }
        if (!this->isAlive())
        {
            throw std::runtime_error("Cannot perform shoot. Character is already dead.");
        }

        if (!enemy->isAlive())
        {
            throw std::runtime_error("Cannot perform shoot. Enemy character is already dead.");
        }

        if (bullets > 0)
        {
            enemy->hit(10); // Each bullet does 10 damage points
            bullets--;
        }
        else if (bullets == 0)
        {
            reload();
        }
    }
    void Cowboy::attackNC(Character *other)
    {
        shoot(other);
    }
    bool Cowboy::hasboolets() const
    {
        return bullets > 0;
    }

    void Cowboy::reload()
    {
        if (!isAlive())
        {
            throw std::runtime_error("Cannot perform reload. Character is already dead.");
        }
        bullets = 6;
    }

    std::string Cowboy::print() const
    {
        std::ostringstream oss;
        oss << "C " << getName() << " is at location " << getLocation().print();

        if (isAlive())
        {
            oss << ", has " << getHitPoints() << " hit points and " << bullets << " bullets left.";
        }
        else
        {
            oss << " (";
            oss << getName() << ")"; // Print the name in parentheses if the cowboy is dead
        }

        return oss.str();
    }

    int Cowboy::getbullets() const
    {
        return bullets;
    }

}
