#include "vec2.hpp"

//Have added the definitions


// Default Constructor Method
Vec2::Vec2() 
    : x(0), y(0){
}

// User Defined Constructor Method
Vec2::Vec2(float x, float y) 
    : x(x), y(y){
}

// Addition operator overloading
Vec2& Vec2::operator+=(Vec2 const& v){
	this -> x += v.x;
	this -> y += v.y;
	return *this; 
}

// Subtraction operator overloading
Vec2& Vec2::operator-=(Vec2 const& v){
	this -> x -= v.x;
	this -> y -= v.y;
	return *this; 
}

// Multiplication operator overloading
Vec2& Vec2::operator*=(float s){
	this -> x *= s;
	this -> y *= s;
	return *this; 
}

// Division operator overloading
Vec2& Vec2::operator/=(float s) {
   this -> x /= s;
   this -> y /= s;
    return *this;
}

// Addition operator overloading
Vec2 operator+(const Vec2& u, const Vec2& v) {

    Vec2 Object;
    Object.x = u.x+v.x;
    Object.y = u.y+v.y;

    return Object;
}

// Subtraction operator overloading
Vec2 operator-(const Vec2& u, const Vec2& v) {

    Vec2 Object;
    Object.x = u.x-v.x;
    Object.y = u.y-v.y;

    return Object;
}

// Multiplication with a float operator overloading
Vec2 operator*(Vec2 const& v, float s) {

    Vec2 Object;
    Object.x = v.x*s;
    Object.y = v.y*s;

    return Object;
}

// Division with a float operator overloading
Vec2 operator/(Vec2 const& v, float s) {

    Vec2 Object;
    Object.x = v.x*s;
    Object.y = v.y*s;

    return Object;
}

// Multiplication with a float operator overloading
Vec2 operator*(float s, Vec2 const& v) {

    Vec2 Object;
    Object.x = s*v.x;
    Object.y = s*v.y;

    return Object;
}