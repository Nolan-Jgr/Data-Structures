//Name:         Nolan Jaeger
//Class:        CS 3305
//Term:         Spring 2021
//Instructor:   Dr.Haddad
//Assignment:   8
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cassert>
using namespace std;
double findAverage(int x[], int i, int n);


int main() {
    cout << "1. Enter class size\n2. Enter class grades\n3. Compute class average\n4. Quit" << endl;
    int input;
    cin >> input;
    cout << endl;
    int size = 0;
    int* grades = new int[0];
    do{
        switch(input)
        {
            case 1:{
                cout << "Enter class size: " << endl;
                cin >> size;
                cout << endl;
            }
            break;
            case 2:{
                grades = new int[size];
                cout << "Enter all class grades" << endl;
                for(int i = 0; i < size;i++)
                {
                    cin >> grades[i];
                }
                cout << endl;
            }
            break;
            case 3:{
                cout << "You entered class size: " << size << endl;
                cout << "You entered grades: ";
                for(int i = 0; i < size;i++)
                {
                    cout << grades[i] << " ";
                }
                cout << endl;
                cout << "Computed Average: " << findAverage(grades,0,size) << endl;
            }
            break;
            case 4:{
                break;
            }
            default:
                cout << "invalid input" << endl;
        }
        cout << "1. Enter class size\n2. Enter class grades\n3. Compute class average\n4. Quit" << endl;
        cin >> input;
        cout << endl;

    }while(input != 4);

}
double findAverage(int x[],int i,int n)
{
    // Last element
    if (i == n-1)
        return x[i];

    // When index is 0, divide sum computed so
    // far by n.
    if (i == 0)
        return ((x[i] + findAverage(x, i+1, n))/n);

    // Compute sum
    return (x[i] + findAverage(x, i+1, n));
}
