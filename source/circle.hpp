#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle{

public:
    Circle();
    Circle(Vec2 const& _center, float _radius, Color const& _color);

    Vec2 get_center() const;
    float get_radius() const;
    float circumference() const;
    Color get_color() const;

    void draw(Window const& _win, Color const& overload_col);
    
        

private:
    Vec2 center;
    float radius;
    Color col;
};

#endif // CIRCLE2_HPP