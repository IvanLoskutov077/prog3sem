#include <iostream>
#include <cmath>
#include "point.hpp"

using std::cout, std::endl;

class Circle
{
private:
    Point center;
    float radius;

public:
    Circle(const Point& center, float radius)
        : center(center), radius(radius >= 0 ? radius : 0) {}

    Circle()
        : center(Point(0, 0)), radius(1) {}

    Circle(const Circle& circle)
        : center(circle.center), radius(circle.radius) {}

    Point getCenter() const { return center; }
    void setCenter(const Point& center) { this->center = center; }

    float getRadius() const { return radius; }
    void setRadius(float radius) { this->radius = radius >= 0 ? radius : 0; }

    float area() const { return M_PI * radius * radius; }

    float distance(const Point& p) const {
        float dist = center.distance(p);
        return std::max(0.0f, dist - radius);
    }

    bool isColliding(const Circle& c) const {
        float dist = center.distance(c.center);
        return dist <= (radius + c.radius);
    }

    void move(const Point& p) {
        center = center + p;
    }
};

int main()
{
    Point p = {7, -1};
    Point q = {-4, 2};
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "p + q = " << p + q << endl;

    Circle a({4, 1}, 3);
    Circle b;

    cout << "Circle a: center: " << a.getCenter() << " radius: " << a.getRadius() << endl;
    cout << "Circle b: center: " << b.getCenter() << " radius: " << b.getRadius() << endl;

    cout << "Area of a = " << a.area() << endl;
    cout << "Distance from point p to circle a = " << a.distance(p) << endl;

    cout << "Collisions:" << endl;
    if (a.isColliding(b))
        cout << "Yes, a is colliding b" << endl;
    else
        cout << "No, a isn't colliding b" << endl;

    cout << "Moving b by {1, 1}:" << endl;
    b.move({1, 1});
    if (a.isColliding(b))
        cout << "Yes, a is colliding b" << endl;
    else
        cout << "No, a isn't colliding b" << endl;
}