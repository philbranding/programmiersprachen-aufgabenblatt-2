#ifndef MAT2_HPP //This checks if the header is already declared some else.
#define MAT2_HPP //This then difines the header if not defined already.
#include "vec2.hpp"

struct Mat2
{
	public:
		//Constructors
	    
	    Mat2(); //default
	    Mat2(float a, float b, float c, float d);//intialisation
	    
	    

	    // Member variables 
	    float a_TopLeft;
	    float b_TopRight;
	    float c_DownLeft;
	    float d_DownRight;

		Mat2& operator*=(Mat2 const& m);
		float det() const;
		

};

	Mat2 operator*(Mat2 const& m1, Mat2 const& m2);
	Vec2 operator*(Mat2 const& m , Vec2 const& v);
	Vec2 operator*(Vec2 const& v , Mat2 const& m);
	Mat2 inverse (Mat2 const& m);
	Mat2 transpose (Mat2 const& m);
	Mat2 make_rotation_mat2 (float phi);


#endif//MAT2_HPP