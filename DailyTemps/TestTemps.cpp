// Name: Nolan Jaeger
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 2
#include <iostream>
#include "DailyTemps.cpp"
#include <cassert>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    DailyTemps temperatures;
    temperatures.printTemps();
    char set;
    cout << "would you like to change the temperature of a certain day?(y or n)";
    cin >> set;
    while(set != 'n')
    {
        temperatures.setTemp();
        cout << "would you like to change the temperature of a certain day?(y or n)";
        cin >> set;
    }
    temperatures.printTemps();
    cout << "Number of Freezing days: " << temperatures.Freezing() << endl;
    temperatures.Warmest();
    return EXIT_SUCCESS;
}
