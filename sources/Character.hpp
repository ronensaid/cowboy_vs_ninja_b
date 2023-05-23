#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>

namespace ariel
{
    class Character
    {
    private:
        std::string name;
        Point location;
        int hitPoints;
        bool isin;
        bool isLeader;  // Add this line
        

    public:
        Character(); // Default constructor
        Character(const std::string &name, const Point &location, int hitPoints);
        virtual ~Character() = default;
        Character(const Character &other) = default;            // copy constructor
        Character &operator=(const Character &other) = default; // copy assignment operator
        Character(Character &&other) = default;                 // move constructor
        Character &operator=(Character &&other) = default;      // move assignment operator

        void setLeader(bool isLeader);  // Add this line
        bool getLeader();  // Add this line
        bool isAlive() const;
        double distance(const Character* other) const;
        void hit(int damage);
        std::string getName() const;
        Point getLocation() const;
        virtual std::string print() const;
        void setin(bool inT);
        bool getin();
        void setName(const std::string &newName);
        void setLocation(const Point &newLocation);
        int getHitPoints() const;
        void setHitPoints(int newHitPoints);
        virtual void attackNC(Character *other) = 0;//to evade the problem in the team class
    };
}
#endif
