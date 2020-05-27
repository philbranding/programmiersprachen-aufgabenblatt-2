#ifndef COLOR_HPP
#define COLOR_HPP
#include "window.hpp"

struct Color{
	Color();
	Color(float rgb);
	Color(float r,float g, float b);

		float red   ;
		float green ;
		float blue ;
};
#endif