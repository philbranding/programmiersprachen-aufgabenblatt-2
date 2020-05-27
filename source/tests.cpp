#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include "vec2.hpp"
#include "mat2.hpp"

// Vec2::Vec2(): x(0), y(0)
TEST_CASE("Testing default Constructor","[Constructor]"){
	Vec2 a;
	REQUIRE(a.x == 0.0f);
	REQUIRE(a.y == 0.0f);

	Vec2 b{5.1f, -9.3f};
	REQUIRE(5.1f == Approx(b.x));
	REQUIRE(-9.3f == Approx(b.y));
}


//Vec2::Vec2(float x, float y): x(x), y(y)
TEST_CASE("Testing User Defined Constructor","[Constructor]"){
	Vec2 a{0.0,0.0};
	REQUIRE(a.x == 0.0f);
	REQUIRE(a.y == 0.0f);

	Vec2 b{5.5,2.2};
	REQUIRE(b.x == 5.5f);
	REQUIRE(b.y == 2.2f);

	Vec2 c{-5.5,-2.2};
	REQUIRE(c.x == -5.5f);
	REQUIRE(c.y == -2.2f);
}

//Vec2& Vec2::operator+=(Vec2 const& v)
TEST_CASE("Testing the +=operator","[operator]"){
	
	Vec2 a{0.0,0.0};
	Vec2 b{0.0,0.0};
	a+=b;
	REQUIRE(a.x == 0.0f);
	REQUIRE(a.y == 0.0f);

	Vec2 c{-1.0,-5.5};
	Vec2 d{-2.2,-3.3};
	c+=d;
	REQUIRE(c.x == -3.2f);
	REQUIRE(c.y == -8.8f);

	Vec2 e{1.0,5.5};
	Vec2 f{2.2,3.3};
	e+=f;
	REQUIRE(e.x == 3.2f);
	REQUIRE(e.y == 8.8f);
}

//Vec2& Vec2::operator-=(Vec2 const& v)
TEST_CASE("Testing the -=operator","[operator]"){
	
	Vec2 a{0.0,0.0};
	Vec2 b{0.0,0.0};
	a-=b;
	REQUIRE(a.x == 0.0f);
	REQUIRE(a.y == 0.0f);

	Vec2 c{-1.0,-4.5};
	Vec2 d{-4.4,-3.3};
	c-=d;
	REQUIRE(c.x == 3.4f);
	REQUIRE(c.y == -1.2f);

	Vec2 e{2.8,5.2};
	Vec2 f{2.2,3.2};
	e-=f;
	REQUIRE(e.x == Approx(0.6f));
	REQUIRE(e.y == Approx(2.0f));
}

//Vec2& Vec2::operator*=(float s)
TEST_CASE("Testing the *=operator","[operator]"){
	
	Vec2 a{0.0,0.0};
	a*=0;
	REQUIRE(a.x == 0.0f);
	REQUIRE(a.y == 0.0f);

	Vec2 c{-1.0,4.5};
	c*=-1;
	REQUIRE(c.x == Approx(1.0f));
	REQUIRE(c.y == Approx(-4.5f));

	Vec2 e{2.8,5.2};
	e*=10;
	REQUIRE(e.x == Approx(28.0f));
	REQUIRE(e.y == Approx(52.0f));
}

//Vec2& Vec2::operator/=(float s)
TEST_CASE("Testing the /=operator","[operator]"){
	
	Vec2 a{0.0,0.0};
	a/=1;
	REQUIRE(a.x == 0.0f);
	REQUIRE(a.y == 0.0f);

	Vec2 c{-10.0,5.5};
	c/=-1;
	REQUIRE(c.x == 10.0f);
	REQUIRE(c.y == -5.5f);

	Vec2 e{50.0,5.0};
	e/=5;
	REQUIRE(e.x == Approx(10.0f));
	REQUIRE(e.y == Approx(1.0f));
}


//Vec2 operator+(const Vec2& u, const Vec2& v)
TEST_CASE("Testing Two Vector Addition +operator","[operator]"){
	

	Vec2 a{0.0,0.0};
	Vec2 b{0.0,0.0};
	
	Vec2 c = a+b;
	REQUIRE(c.x == Approx(0.0f));
	REQUIRE(c.y == Approx(0.0f));

	Vec2 d{-1.0,-1.0};
	Vec2 e{-4.4,-3.3};
	
	Vec2 g = d+e;
	REQUIRE(g.x == Approx(-5.4f));
	REQUIRE(g.y == Approx(-4.3f));

	Vec2 f{2.8,5.2};
	Vec2 i{2.2,3.2};
	
	Vec2 h = f+i;
	REQUIRE(h.x == Approx(5.0f));
	REQUIRE(h.y == Approx(8.4f));
}


//Vec2 operator-(const Vec2& u, const Vec2& v)
TEST_CASE("Testing Two Vector Subtraction -operator","[operator]"){
	

	Vec2 a{0.0,0.0};
	Vec2 b{0.0,0.0};
	
	Vec2 c = a-b;
	REQUIRE(c.x == Approx(0.0f));
	REQUIRE(c.y == Approx(0.0f));

	Vec2 d{-10.0,-1.0};
	Vec2 e{-2.0,-2.0};
	
	Vec2 g = d-e;
	REQUIRE(g.x == Approx(-8.0f));
	REQUIRE(g.y == Approx(1.0f));

	Vec2 f{8.8,6.6};
	Vec2 i{2.2,1.1};
	
	Vec2 h = f-i;
	REQUIRE(h.x == Approx(6.6f));
	REQUIRE(h.y == Approx(5.5f));
}

//Vec2 operator*(Vec2 const& v, float s)
TEST_CASE("Testing Vector x Float Multiplication *operator","[operator]"){
	

	Vec2 a{0.0,0.0};

	Vec2 c = a*0.0f;

	REQUIRE(c.x == Approx(0.0f));
	REQUIRE(c.y == Approx(0.0f));

	Vec2 d{-10.0,-2.0};
	
	Vec2 g = d *-20.0f;

	REQUIRE(g.x == Approx(200.0f));
	REQUIRE(g.y == Approx(40.0f));

	Vec2 f{5.0,10.0};
	
	Vec2 h =  f*2.0f;
	REQUIRE(h.x == Approx(10.0f));
	REQUIRE(h.y == Approx(20.0f));
}

//Vec2 operator/(Vec2 const& v, float s)
TEST_CASE("Testing Vector / Float Division /operator","[operator]"){
	

	Vec2 a{0.0,0.0};

	Vec2 c = (a/1.0f);

	REQUIRE(c.x == Approx(0.0f));
	REQUIRE(c.y == Approx(0.0f));

	Vec2 d{-10.0,2.0};
	
	Vec2 g = (d /-2.0f);

	REQUIRE(g.x == Approx(20.0f));
	REQUIRE(g.y == Approx(-4.0f));

	Vec2 f{5.0,10.0};
	
	Vec2 h =  (f/5.0f);

	REQUIRE(h.x == Approx(25.0f));
	REQUIRE(h.y == Approx(50.0f));
}

//Vec2 operator*(float s, Vec2 const& v)
TEST_CASE("Testing Float x Vector Multiplication *operator","[operator]"){
	

	Vec2 a{0.0,0.0};

	Vec2 c = 0.0f*a;

	REQUIRE(c.x == Approx(0.0f));
	REQUIRE(c.y == Approx(0.0f));

	Vec2 d{-10.0,-2.0};
	
	Vec2 g = -10.0f * d;

	REQUIRE(g.x == Approx(100.0f));
	REQUIRE(g.y == Approx(20.0f));

	Vec2 f{5.0,10.0};
	
	Vec2 h = 0.20 * f;
	REQUIRE(h.x == Approx(1.0f));
	REQUIRE(h.y == Approx(2.0f));
}


// Default Constructor and User Defined test Mat2();
TEST_CASE("Testing Mat2 Constructors","[Constructor]"){
	

	Mat2 a;
	REQUIRE(a.e_00 == 1.0f);
	REQUIRE(a.e_10 == 0.0f);
	REQUIRE(a.e_01 == 1.0f);
	REQUIRE(a.e_11 == 0.0f);

	Mat2 b{10.3,5.6,1.0,8.6};
	REQUIRE(b.e_00 == 10.3f);
	REQUIRE(b.e_10 == 5.6f);
	REQUIRE(b.e_01 == 1.0f);
	REQUIRE(b.e_11 == 8.6f);

	Mat2 c{-0.3,-0.6,-0.4,-0.7};
	REQUIRE(c.e_00 == -0.3f);
	REQUIRE(c.e_10 == -0.6f);
	REQUIRE(c.e_01 == -0.4f);
	REQUIRE(c.e_11 ==-0.7f);	
}

// float det() const;
TEST_CASE("Testing FloatDet operator","[FloatDet]"){
	

	Mat2 a{};
	REQUIRE(a.det()  == Approx(0.0f));
	

	Mat2 b{10.3,5.6,1.0,8.6};
	REQUIRE(b.det()  == Approx (82.98f));
	

	Mat2 c{-0.3,-0.6,-0.4,-0.7};
	REQUIRE(c.det()  == Approx(-0.03f));
}

// Mat2 operator*(Mat2 const& m1, Mat2 const& m2);
TEST_CASE("Testing Mutltiplying two Mat2 Matrix *operator","[operator]"){
	
	Mat2 a{}; //Default
	Mat2 b{10.3,5.6,1.0,8.6};

	a*=b;
	REQUIRE(a.e_00 == 10.3f);
	REQUIRE(a.e_10 == 5.6f);
	REQUIRE(a.e_01 == 10.3f);
	REQUIRE(a.e_11 == 5.6f);

	Mat2 c{-0.3,-0.6,-0.4,-0.7};
	Mat2 d{-10.3,-5.6,-1.0,-8.6};

	c*=d;
	REQUIRE(c.e_00 == 3.69f);
	REQUIRE(c.e_10 == 6.84f);
	REQUIRE(c.e_01 == 4.82f);
	REQUIRE(c.e_11 == 8.26f);

	Mat2 e{1.0,2.0,3.0,4.0};
	Mat2 f{0.5,0.6,0.7,0.8};

	e*=f;
	REQUIRE(e.e_00 == 1.9f);
	REQUIRE(e.e_10 == 2.2f);
	REQUIRE(e.e_01 == 4.3f);
	REQUIRE(e.e_11 == 5.0f);
}

// Mat2 operator*(Mat2 const& m1, Mat2 const& m2);
TEST_CASE("Testing Mutltiplying Mat3/Mat4/Mat54 Matrix *operator","[operator]"){
	
	Mat2 a{}; //Default
	Mat2 b{10.3,5.6,1.0,8.6};

	Mat2 Mat3 = a*b;

	REQUIRE(Mat3.e_00 == 10.3f);
	REQUIRE(Mat3.e_10 == 5.6f);
	REQUIRE(Mat3.e_01 == 10.3f);
	REQUIRE(Mat3.e_11 == 5.6f);

	Mat2 c{-0.3,-0.6,-0.4,-0.7};
	Mat2 d{-10.3,-5.6,-1.0,-8.6};

	Mat2 Mat4 = c*d;

	REQUIRE(Mat4.e_00 == 3.69f);
	REQUIRE(Mat4.e_10 == 6.84f);
	REQUIRE(Mat4.e_01 == 4.82f);
	REQUIRE(Mat4.e_11 == 8.26f);

	Mat2 e{1.0,2.0,3.0,4.0};
	Mat2 f{0.5,0.6,0.7,0.8};

	Mat2 Mat5 = e*f;

	REQUIRE(Mat5.e_00 == 1.9f);
	REQUIRE(Mat5.e_10 == 2.2f);
	REQUIRE(Mat5.e_01 == 4.3f);
	REQUIRE(Mat5.e_11 == 5.0f);
}

// Vec2 operator*(Mat2 const& m, Vec2 const& v);
TEST_CASE("Testing Mutltiplying  Mat2 X Vec2 *operator","[operator]"){
	
	Mat2 a{}; //Default
	Vec2 Vb{}; //Default

	Vec2 Vec3 = a*Vb;

	REQUIRE(Vec3.x == Approx(0.0f));
	REQUIRE(Vec3.y == Approx(0.0f));
	

	Mat2 c{-0.3,-0.6,-0.4,-0.7};
	Vec2 Vd{-10.3,-5.6};

	Vec2 Vec4 = c*Vd;

	REQUIRE(Vec4.x == Approx(6.45f));
	REQUIRE(Vec4.y == Approx(8.04f));
	
	
	Mat2 e{1.0,2.0,3.0,4.0};
	Vec2 Vf{0.2,10.0,};

	Vec2 Vec5 = e*Vf;

	REQUIRE(Vec5.x == Approx(20.2f));
	REQUIRE(Vec5.y == Approx(40.6f));
}


// Vec2 operator*(Vec2 const& v, Mat2 const& m);
TEST_CASE("Testing Mutltiplying  Vec2 X Mat2 *operator","[operator]"){
	
	Mat2 a{}; //Default
	Vec2 Vb{}; //Default

	Vec2 Vec3 = Vb*a;

	REQUIRE(Vec3.x == Approx(0.0f));
	REQUIRE(Vec3.y == Approx(0.0f));
	

	Mat2 c{-0.3,-0.6,-0.4,-0.7};
	Vec2 Vd{-10.3,-5.6};

	Vec2 Vec4 = Vd*c;

	REQUIRE(Vec4.x == Approx(6.45f));
	REQUIRE(Vec4.y == Approx(8.04f));
	
	
	Mat2 e{1.0,2.0,3.0,4.0};
	Vec2 Vf{0.2,10.0,};

	Vec2 Vec5 = Vf*e;

	REQUIRE(Vec5.x == Approx(20.2f));
	REQUIRE(Vec5.y == Approx(40.6f));
}

// Mat2 inverse(Mat2 const& m);
TEST_CASE("Testing Inverse of Mat2 inverseMatrix","[inverseMatrix]"){
	

	Mat2 c{-0.3,-0.6,-0.4,-0.7};
	Mat2 d = inverse(c);

	REQUIRE(d.e_00 == Approx(23.33333));
	REQUIRE(d.e_10 == Approx(-20.0f));
	REQUIRE(d.e_01 == Approx(-13.33333f));
	REQUIRE(d.e_11 == Approx(10.0f));

	Mat2 e{1.0,2.0,3.0,4.0};
	Mat2 f = inverse(e);

	REQUIRE(f.e_00 == Approx(-2.0f));
	REQUIRE(f.e_01 == Approx(1.5f));
	REQUIRE(f.e_10 == Approx(1.0f));
	REQUIRE(f.e_11 == Approx(-0.5f));
}

//Mat2 transpose(Mat2 const& m)
TEST_CASE("Testing Inverse of Mat2 transposeMatrix","[transposeMatrix]"){
	
	Mat2 a{};
	Mat2 b = transpose(a);

	REQUIRE(b.e_00 == Approx(1.0));
	REQUIRE(b.e_10 == Approx(1.0f));
	REQUIRE(b.e_01 == Approx(0.0f));
	REQUIRE(b.e_11 == Approx(0.0f));
	
	Mat2 c{-0.3,-0.6,-0.4,-0.7};
	Mat2 d = transpose(c);

	REQUIRE(d.e_00 == Approx(-0.3));
	REQUIRE(d.e_10 == Approx(-0.4f));
	REQUIRE(d.e_01 == Approx(-0.6f));
	REQUIRE(d.e_00 == Approx(-0.3f));

	Mat2 e{1.1,2.2,3.3,4.4};
	Mat2 f = transpose(e);

	REQUIRE(f.e_00 == Approx(1.1f));
	REQUIRE(f.e_10 == Approx(3.3f));
	REQUIRE(f.e_01 == Approx(2.2f));
	REQUIRE(f.e_11 == Approx(4.4f));
}

//Mat2 make_rotation_mat2(float phi)
TEST_CASE("Testing Inverse of Mat2 rotationMatrix","[rotationMatrix]"){
	
	Mat2 b = make_rotation_mat2(180.0f);

	REQUIRE(b.e_00 == Approx(0.80115f));
	REQUIRE(b.e_10 == Approx(0.0));
	REQUIRE(b.e_01 == Approx(-0.80115f));
	REQUIRE(b.e_11 == Approx(-0.59846));
	
	Mat2 c{-0.3,-0.6,-0.4,-0.7};
	Mat2 d = c*(make_rotation_mat2(-0.5f));

	REQUIRE(d.e_00 == Approx(0.14383f));
	REQUIRE(d.e_10 == Approx(-0.52655f));
	REQUIRE(d.e_01 == Approx(0.14383f));
	REQUIRE(d.e_11 == Approx(-0.61431f));

	Mat2 e{1.1,2.2,3.3,4.4};
	Mat2 f = e*(make_rotation_mat2(10.0));

	REQUIRE(f.e_00 == Approx(-0.59842f));
	REQUIRE(f.e_10 == Approx(-1.84596f));
	REQUIRE(f.e_01 == Approx(-0.59842f));
	REQUIRE(f.e_11 == Approx(-3.69191f));
}







int main(int argc, char *argv[])
{

  return Catch::Session().run(argc, argv);
}
