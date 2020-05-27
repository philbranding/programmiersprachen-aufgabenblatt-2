#include <iostream>
using namespace std;

/* A complete demonstration - base class, derived classes (and derived class
from derived class too), with an array of various objects of the similar types
and code to access those objects */

class Shape {
        public:
                float width;
                float height;
                virtual float getarea() {} ; };
class Circle: public Shape {
        public:
                Circle(float radius);
                float getarea() ; };
class Rectangle: public Shape {
        public:
                Rectangle(float width, float height);
                float getarea() ; };
class Square: public Rectangle {
        public:
                Square(float size); };

Square::Square (float size) : Rectangle(size, size) { }
Rectangle::Rectangle(float width, float height) {
        this->width = width; this->height = height; }
Circle::Circle (float radius) {
        this->width = this->height = radius * 2.0; }

float Circle::getarea() { return width * width * 3.14159265 / 4.0; }
float Rectangle::getarea() { return width * height ; }

int main (int argc, char **argv) {

        Shape * papers[5];

        Circle michael(15.0);
        Rectangle andrew(34.0,2.0);
        Circle ann(2.3);
        Square tim(3.33);
        Rectangle jonathan(5.61,7.92);

        papers[0] = &michael; papers[1] = &andrew; papers[2] = &ann;
        papers[3] = &tim; papers[4] = &jonathan;

        for (int k=0; k<5; k++) {
                cout << "Area is " << papers[k]->getarea() << endl;
        }

