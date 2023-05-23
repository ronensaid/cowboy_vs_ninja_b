#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Ninja.hpp"
#include <string>
namespace ariel
{

    class OldNinja : public Ninja
    {
    public:
        OldNinja(const std::string &name, const Point &location);

    };
}

#endif /* OLDNINJA_HPP */