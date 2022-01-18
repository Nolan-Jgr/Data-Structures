// Name: Nolan Jaeger
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 2
#ifndef DAILYTEMPS_DAILYTEMPS_H
#define DAILYTEMPS_DAILYTEMPS_H
#include <iostream>
#include <string>

class DailyTemps {
private:
    int nums[7];
public:
    DailyTemps();
    void setTemp();
    int Freezing();
    void Warmest();
    void printTemps();

};


#endif //DAILYTEMPS_DAILYTEMPS_H
