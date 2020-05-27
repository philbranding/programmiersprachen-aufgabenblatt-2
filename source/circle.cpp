#include "circle.hpp"
#include <cmath>

Circle::Circle(Vec2 const& _center, float _radius, Color const& _color):
center{_center},
radius{fabs(_radius)},
col{_color}
{

}

Vec2 Circle::get_center() const{
    
    return center;
}

float Circle::get_radius() const{
    return radius;
}

float Circle::circumference() const{

    return 2*M_PI*get_radius();
}

Color Circle::get_color() const{
    return col;
}

void Circle::draw(Window const& _win, Color const& overload_col){

    _win.draw_point(center.x,center.y,col.r, col.g, col.b);

    _win.draw_line(center.x+radius, center.y-50.0f, center.x+radius, center.y+50.0f,
        overload_col.r, overload_col.g, overload_col.b
        );
    _win.draw_line(center.x-radius, center.y-50.0f, center.x-radius, center.y+50.0f,
        overload_col.r, overload_col.g, overload_col.b
        );
        
    _win.draw_line(center.x+50.0f, center.y+radius, center.x-50.0f, center.y+radius,
        overload_col.r, overload_col.g, overload_col.b
        );

    _win.draw_line(center.x-50.0f, center.y-radius, center.x+50.0f, center.y-radius,
        overload_col.r, overload_col.g, overload_col.b
        );
        
    _win.draw_line(center.x+radius, center.y+50.0f, center.x+50.0f, center.y+radius,
        overload_col.r, overload_col.g, overload_col.b
        );
    
    _win.draw_line(center.x-radius, center.y+50.0f, center.x-50.0f, center.y+radius,
        overload_col.r, overload_col.g, overload_col.b
        );
    
    _win.draw_line(center.x-radius, center.y-50.0f, center.x-50.0f, center.y-radius,
        overload_col.r, overload_col.g, overload_col.b
        );
    
    _win.draw_line(center.x+radius, center.y-50.0f, center.x+50.0f, center.y-radius,
        overload_col.r, overload_col.g, overload_col.b
        );        
}
