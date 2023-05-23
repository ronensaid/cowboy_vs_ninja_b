#include <cmath>
#include <sstream>
#include "Point.hpp"
using namespace ariel;

// Constructor
Point::Point(double pointx, double pointy) : pointx(pointx), pointy(pointy) {}

double Point::distance(const Point &other) const
{
    double dx = pointx - other.pointx;
    double dy = pointy - other.pointy;
    return std::sqrt(dx * dx + dy * dy);
}

std::string Point::print() const
{
    std::ostringstream oss;
    oss << "(" << pointx << ", " << pointy << ")";
    return oss.str();
}

Point Point::moveTowards(const Point &source, const Point &target, double maxDistance)
{
    if(maxDistance < 0)
    {
        throw std::invalid_argument("maxDistance must be non-negative");
    }
    double targetDistance = source.distance(target);
    if (targetDistance <= maxDistance)
    {
        return target;
    }
    else
    {
        double ratio = maxDistance / targetDistance;
        double newX = source.getX() + (target.getX() - source.getX()) * ratio;
        double newY = source.getY() + (target.getY() - source.getY()) * ratio;
        return Point(newX, newY);
    }
}

double Point::getX() const
{
    return pointx;
}

void Point::setX(double new_x)
{
    this->pointx = new_x;
}

double Point::getY() const
{
    return pointy;
}

void Point::setY(double new_y)
{
    this->pointy = new_y;
}
