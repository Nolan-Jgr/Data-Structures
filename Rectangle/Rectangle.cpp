// Name: Nolan Jaeger
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 2
#include <iostream>
#include <string>
#include "Rectangle.h"

using namespace std;
Rectangle::Rectangle(){
    width = 1.00;
    height = 1.00;
}
Rectangle::Rectangle(double w, double h) {
    width = w;
    height = h;
}
double Rectangle::getWidth() {
    return width;
}
double Rectangle::getHeight() {
    return height;
}
double Rectangle::getArea() {
    return (width * height);
}
double Rectangle::getPerimeter() {
    return (2*width) + (2*height);
}
void Rectangle::printRectangle(string ObjName) {
    cout <<  "This Rectangle " << ObjName << " has width " << width << " and  height " << height << endl;
}


