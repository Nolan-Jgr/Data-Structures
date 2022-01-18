// Name: Nolan Jaeger
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 2
#include "DailyTemps.h"
#include <iostream>
#include <string>

using namespace std;
DailyTemps::DailyTemps() {
    cout << "Enter the temperatures for each day of the week" << endl;
    for(int i = 0; i < 7; i++) {
        switch (i) {
            case 0:
                cout << "Enter Monday Temp: ";
                cin >> nums[0];
                break;
            case 1:
                cout << "Enter Tuesday Temp: ";
                cin >> nums[1];
                break;
            case 2:
                cout << "Enter Wednesday Temp: ";
                cin >> nums[2];
                break;
            case 3:
                cout << "Enter Thurday Temp: ";
                cin >> nums[3];
                break;
            case 4:
                cout << "Enter Friday Temp: ";
                cin >> nums[4];
                break;
            case 5:
                cout << "Enter Saturday Temp: ";
                cin >> nums[5];
                break;
            default:
                cout << "Enter Sunday Temp: ";
                cin >> nums[6];
        }
    }
}
void DailyTemps::setTemp() {
    int day;
    int temp;
    cout << "Enter the day desired(Monday = 0, Tuesday = 1,..., Sunday = 6): ";
    cin >> day;
    cout << "Enter temp for that day: ";
    cin >> temp;
    nums[day] = temp;
}
int DailyTemps::Freezing() {
    int count = 0;
    for(int i = 0; i < 7; i++)
    {
        if(nums[i] < 32)
        {
            count++;
        }
    }
    return count;
}
void DailyTemps::Warmest() {
    int max = nums[0];
    int day = 0;
    for(int i = 0; i < 7; i++)
    {
        if(nums[i] > max)
        {
            day = i;
            max = nums[i];
        }
    }
    switch(day)
    {
        case 0:
            cout << "The warmest day of the week is Monday" << endl;
            break;
        case 1:
            cout << "The warmest day of the week is Tuesday" << endl;
            break;
        case 2:
            cout << "The warmest day of the week is Wednesday" << endl;
            break;
        case 3:
            cout << "The warmest day of the week is Thursday" << endl;
            break;
        case 4:
            cout << "The warmest day of the week is Friday" << endl;
            break;
        case 5:
            cout << "The warmest day of the week is Saturday" << endl;
            break;
        default:
            cout << "The warmest day of the week is Sunday" << endl;
    }

}
void DailyTemps::printTemps() {
    cout << "Monday\t\t" << nums[0] << endl;
    cout << "Tuesday\t\t" << nums[1] << endl;
    cout << "Wednesday\t" << nums[2] << endl;
    cout << "Thursday\t" << nums[3] << endl;
    cout << "Friday\t\t" << nums[4] << endl;
    cout << "Saturday\t" << nums[5] << endl;
    cout << "Sunday\t\t" << nums[6] << endl;
}

