
#include "mat2.hpp"
#include "vec2.hpp"
#include <cmath>

//The Default Constructor
Mat2::Mat2(): a_TopLeft{1},b_TopRight{0},c_DownLeft{1},d_DownRight{0}{
}

//The User Defined Constructor
Mat2::Mat2(float a, float b, float c, float d): 
a_TopLeft{a},
b_TopRight{b},
c_DownLeft{c},
d_DownRight{d}{
}

//Matrix Multiplication Operator Overload Defination
Mat2& Mat2::operator*=(Mat2 const& m){
  float a_NewTopLeft   = (a_TopLeft * m.a_TopLeft)  + (b_TopRight * m.c_DownLeft);
  float b_NewTopRight  = (a_TopLeft * m.b_TopRight) + (b_TopRight * m.d_DownRight);
  float c_NewDownLeft  = (c_DownLeft * m.a_TopLeft) + (d_DownRight * m.c_DownLeft);
  float d_NewDownRight = (c_DownLeft * m.b_TopRight) + (d_DownRight * m.d_DownRight);

  a_TopLeft  = a_NewTopLeft;
  b_TopRight = b_NewTopRight;
  c_DownLeft = c_NewDownLeft;
  d_DownRight= d_NewDownRight;

  return *this;
}

float Mat2::det() const{
  return ((a_TopLeft*d_DownRight)- (b_TopRight*c_DownLeft)) ;
}


Mat2 operator*(Mat2 const& m1, Mat2 const& m2){
  
  Mat2 Mat2Object;
  Mat2Object.a_TopLeft   = (m1.a_TopLeft  * m2.a_TopLeft)  + (m1.b_TopRight  * m2.c_DownLeft);
  Mat2Object.b_TopRight  = (m1.a_TopLeft  * m2.b_TopRight) + (m1.b_TopRight  * m2.d_DownRight);
  Mat2Object.c_DownLeft  = (m1.c_DownLeft * m2.a_TopLeft)  + (m1.d_DownRight * m2.c_DownLeft);
  Mat2Object.d_DownRight = (m1.c_DownLeft * m2.b_TopRight) + (m1.d_DownRight * m2.d_DownRight);
  
  return Mat2Object;

}

Vec2 operator*(Mat2 const& m, Vec2 const& v){
  
  Vec2 NewObject;
  NewObject.x = (m.a_TopLeft*v.x)  + (m.b_TopRight*v.y);
  NewObject.y = (m.c_DownLeft*v.x) + (m.d_DownRight*v.y);

  return NewObject;
}

Vec2 operator*(Vec2 const& v, Mat2 const& m){
  
  Vec2 NewObject;
  NewObject.x = (v.x*m.a_TopLeft) + (v.y*m.b_TopRight);
  NewObject.y = (v.x*m.c_DownLeft)+ (v.y*m.d_DownRight);

  return NewObject;

}


Mat2 inverse(Mat2 const& m){
  
  Mat2 inverseMatrix;
  inverseMatrix.a_TopLeft   = (1/m.det())*(m.d_DownRight);
  inverseMatrix.b_TopRight  = (1/m.det())*(m.b_TopRight)*-1;
  inverseMatrix.c_DownLeft  = (1/m.det())*(m.c_DownLeft)*-1;
  inverseMatrix.d_DownRight = (1/m.det())*(m.a_TopLeft);

  return inverseMatrix;
}


Mat2 transpose(Mat2 const& m){
  
  Mat2 transposeMatrix;
  transposeMatrix.a_TopLeft  = m.a_TopLeft;
  transposeMatrix.b_TopRight = m.c_DownLeft;
  transposeMatrix.c_DownLeft = m.b_TopRight;
  transposeMatrix.d_DownRight= m.d_DownRight;

  return transposeMatrix;
}


Mat2 make_rotation_mat2(float phi){
  
  Mat2 rotationMatrix;
  rotationMatrix.a_TopLeft   = cos(phi);
  rotationMatrix.b_TopRight  = (sin(phi))*(-1);
  rotationMatrix.c_DownLeft  = sin(phi);
  rotationMatrix.d_DownRight = cos(phi);

  return rotationMatrix;

}