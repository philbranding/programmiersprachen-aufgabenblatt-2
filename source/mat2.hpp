#ifndef MAT2_HPP //This checks if the header is already declared some else.
#define MAT2_HPP //This then difines the header if not defined already.
#include "vec2.hpp"

struct Mat2
{
	public:
		//Constructors
			// matrix layout :
			// e_00 e_10
			// e_01 e_11
	    
	    Mat2(); //default
	    Mat2(float e_00, float e_10, float e_01, float e_11);//intialisation
	    
	    

	    // Member variables 
	    float e_00;
	    float e_10;
	    float e_01;
	    float e_11;

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