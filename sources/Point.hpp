#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
namespace ariel
{

    class Point
    {
        double pointx;
        double pointy;

    public:
        Point(double pointx, double pointy);

        double distance(const Point &other) const;

        std::string print() const;

        static Point moveTowards(const Point &source, const Point &target, double maxDistance);
        // Getter for pointx
        double getX() const;

        // Setter for pointx
        void setX(double new_x);

        // Getter for pointy
        double getY() const;

        // Setter for pointy
        void setY(double new_y);
    };
}
#endif /*POINT_HPP */