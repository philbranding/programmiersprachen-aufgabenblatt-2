#include "rectangle.hpp"
#include "window.hpp"
#include "vec2.hpp"
#include "color.hpp"
#include <cmath>

Rectangle::Rectangle():
 x_{3},
 y_{4}, 
 z_{3,3},
 rgb{0,0,0}{

}

Rectangle::Rectangle(Vec2 v, float x, float y):
x_{x},
y_{y},
v_{v},
rgb{0,0,0}{

}

Rectangle::Rectangle(Vec2 v,float x, float y, Color r):
x_Vec2 {x}, 
y_Vec2{y}, 
v_{v},
rgb{r}{

}

void Rectangle::setHeight(float h){
	x_r = h;
}

float Rectangle::getHeight(){
	return x_;
}

void Rectangle::setLength(float l){
	y_=l;
}

float Rectangle::getLength(){
	return y_;
}

float Rectangle::circumference(){
	float c = 2*x_+2*y_ ;
	return c;
}

float Rectangle::areaOfShape(){
	float a = x_*y_;
	return a;
}


float Rectangle::diagonal(){
	float d = sqrt(x_*x_+y_*y_);
	return d;
}

void Rectangle::draw(Window& win){
	win.draw_line(
		v_.x,
		v_.y,
		x_+v_.x,
		v_.y,
		rgb.red,
		rgb.green,
		rgb.blue);

	win.draw_line(
		x_+v_.x,
		v_.y,
		x_+v_.x,
		y_+v_.y,
		rgb.red,
		rgb.green,
		rgb.blue);

	win.draw_line(
		x_+v_.x,
		y_+v_.y,
	    v_.x,
	    y_+v_.y,
		rgb.red,
		rgb.green,
		rgb.blue);

	win.draw_line(
		v_.x,
		y_+v_.y,
		v_.x,
		v_.y,
		rgb.red,
		rgb.green,
		rgb.blue);

}

void Rectangle::draw(Window& win, Color r){

	win.draw_line(
		v_.x,
		v_.y,
		x_+v_.x,
		v_.y,
		r.red,
		r.green,
		r.blue);

	win.draw_line(
		x_+v_.x,
		v_.y,
		x_+v_.x,
		y_+v_.y,
		r.red,
		r.green,
		r.blue);

	win.draw_line(
		x_+v_.x,
		y_+v_.y,
		v_.x,
		y_+v_.y,
		r.red,
		r.green,
		r.blue);

	win.draw_line(
		v_.x,
		y_+v_.y,
		v_.x,v_.y,
		r.red,
		r.green,
		r.blue);

}


bool Rectangle::is_inside(Vec2 v){
	if(v.x >= v_.x && v.y >= v_.y && v.x <= v_.x+x_ && v.y <= v_.y+y_) 
		return true;
	else return false;
}
