#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"
#include <string>
namespace ariel
{

    class Cowboy : public Character
    {
    private:
        int bullets;

    public:
        Cowboy(std::string name, Point location);

        void shoot(Character *enemy) ;
        bool hasboolets() const;
        void reload() ;
        std::string print() const override;
        int getbullets() const;
        void attackNC(Character *other) override;
    };

}

#endif /* COWBOY_HPP */
