#ifndef NINJA_HPP
#define NINJA_HPP

#include <string>
#include "Character.hpp" // Assuming there's a Character base class

namespace ariel
{
    class Ninja : public Character
    {
    private:
        int speed;

    public:
        Ninja(const std::string &name, const Point &location, int speed, int hitPoints);
        void slash(Character *enemy);
        std::string print() const override;
        int getspeed() const;
        void setspeed(int speed); 
        void move(Character *other);
        void attackNC(Character *other) override;
    };

}

#endif /* NINJA_HPP */
