#include "Ninja.hpp"
#include "TrainedNinja.hpp"

namespace ariel
{

    TrainedNinja::TrainedNinja(const std::string &name, const Point &location)
        : Ninja(name, location, 12, 120)
    {
    }

}
