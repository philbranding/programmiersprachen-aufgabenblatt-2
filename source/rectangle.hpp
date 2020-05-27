#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.cpp"

class Rectangle
{
public:
	Rectangle(); // default Constructor 
	Rectangle(Vec2 const& v, float x, float y); // Vector with two points constructor
	Rectangle(Vec2 const& v, float x, float y, Color const& r); // Vector with two points and a Color constructor
	float x_; //Height
	float y_; //Lenght
	Vec2 v_; // Vector Instance
	Color rgb; // Color Instance

	//Getter Methods
	float getHeight();
	float getLenght(); 

	float circumference();
	float areaOfShape();
	float diagonal();

	//Window Draw Methods
	void draw( Window& window);
	void draw(Window& window, Color r)
	bool is_inside(Vec2 v);

	//Setter Methods
	void setHeight(float x); 
	void setLenght(float y);

#endif