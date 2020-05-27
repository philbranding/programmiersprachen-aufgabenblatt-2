
#include "mat2.hpp"
#include "vec2.hpp"
#include <cmath>

//The Default Constructor
// matrix layout :
// e_00 e_10
// e_01 e_11
Mat2::Mat2(): e_00{1.0f},e_10{0.0f},e_01{1.0f},e_11{0.0f}{
}

//The User Defined Constructor
Mat2::Mat2(float a, float b, float c, float d): 
e_00{a},
e_10{b},
e_01{c},
e_11{d}{
}

//Matrix Multiplication Operator Overload Defination
Mat2& Mat2::operator*=(Mat2 const& m){
  float e_New00 = (e_00 * m.e_00) + (e_10 * m.e_01);
  float e_New10 = (e_00 * m.e_10) + (e_10 * m.e_11);
  float e_New01 = (e_01 * m.e_00) + (e_11 * m.e_01);
  float e_New11 = (e_01 * m.e_10) + (e_11 * m.e_11);

  e_00 = e_New00;
  e_10 = e_New10;
  e_01 = e_New01;
  e_11 = e_New11;

  return *this;
}

float Mat2::det() const{
  return ((e_00*e_11)- (e_10*e_01)) ;
}


Mat2 operator*(Mat2 const& m1, Mat2 const& m2){
  
  Mat2 Mat2Object;
  Mat2Object.e_00 = (m1.e_00 * m2.e_00) + (m1.e_10 * m2.e_01);
  Mat2Object.e_10 = (m1.e_00 * m2.e_10) + (m1.e_10 * m2.e_11);
  Mat2Object.e_01 = (m1.e_01 * m2.e_00) + (m1.e_11 * m2.e_01);
  Mat2Object.e_11 = (m1.e_01 * m2.e_10) + (m1.e_11 * m2.e_11);
  
  return Mat2Object;

}

Vec2 operator*(Mat2 const& m, Vec2 const& v){
  
  Vec2 NewObject;
  NewObject.x = (m.e_00*v.x) + (m.e_10*v.y);
  NewObject.y = (m.e_01*v.x) + (m.e_11*v.y);

  return NewObject;
}

Vec2 operator*(Vec2 const& v, Mat2 const& m){
  
  Vec2 NewObject;
  NewObject.x = (v.x*m.e_00) + (v.y*m.e_10);
  NewObject.y = (v.x*m.e_01) + (v.y*m.e_11);

  return NewObject;

}


Mat2 inverse(Mat2 const& m){
  
  Mat2 inverseMatrix;
  inverseMatrix.e_00 = (1/m.det())*(m.e_11);
  inverseMatrix.e_10 = (1/m.det())*(m.e_10)*-1;
  inverseMatrix.e_01 = (1/m.det())*(m.e_01)*-1;
  inverseMatrix.e_11 = (1/m.det())*(m.e_00);

  return inverseMatrix;
}


Mat2 transpose(Mat2 const& m){
  
  Mat2 transposeMatrix;
  transposeMatrix.e_00 = m.e_00;
  transposeMatrix.e_10 = m.e_01;
  transposeMatrix.e_01 = m.e_10;
  transposeMatrix.e_11 = m.e_11;

  return transposeMatrix;
}


Mat2 make_rotation_mat2(float phi){
  
  Mat2 rotationMatrix;
  rotationMatrix.e_00 = cos(phi);
  rotationMatrix.e_00 = (sin(phi))*(-1);
  rotationMatrix.e_01 = sin(phi);
  rotationMatrix.e_11 = cos(phi);

  return rotationMatrix;

}