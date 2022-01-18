// Name: Nolan Jaeger
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 2
#ifndef RECTANGLE_RECTANGLE_H
#define RECTANGLE_RECTANGLE_H
#include <iostream>
#include <string>
using namespace std;

class Rectangle {
private:
    double width;
    double height;
public:
    Rectangle();
    Rectangle(double w, double h);
    double getWidth();
    double getHeight();
    double getArea();
    double getPerimeter();
    void printRectangle(string ObjName);
};


#endif //RECTANGLE_RECTANGLE_H
