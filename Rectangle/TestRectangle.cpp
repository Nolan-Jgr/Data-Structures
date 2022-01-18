// Name: Nolan Jaeger
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 25
#include "Rectangle.cpp"
#include "Rectangle.h"
#include <cassert>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
    double x;
    double y;
    cout << "Enter width for herRectangle: ";
    cin >> x;
    cout << "Enter height for herRectangle: ";
    cin >> y;
    Rectangle myRectangle;
    Rectangle herRectangle(x,y);

    cout << "MyRectangle" << endl;
    cout << "-----------" << endl;
    cout << "Width: " << myRectangle.getWidth() << endl;
    cout << "Height: " << myRectangle.getHeight() << endl;
    cout << "Area: " << myRectangle.getArea() << endl;
    cout << "Perimeter: " << myRectangle.getPerimeter() << endl;
    cout << "" << endl;
    myRectangle.printRectangle("myRectangle");
    cout << "" << endl;

    cout << "HerRectangle" << endl;
    cout << "------------" << endl;
    cout << "Width: " << herRectangle.getWidth() << endl;
    cout << "Height: " << herRectangle.getHeight() << endl;
    cout << "Area: " << herRectangle.getArea() << endl;
    cout << "Perimeter: " << herRectangle.getPerimeter() << endl;
    cout << "" << endl;
    herRectangle.printRectangle("herRectangle");
    cout << "" << endl;

    return EXIT_SUCCESS;
}
