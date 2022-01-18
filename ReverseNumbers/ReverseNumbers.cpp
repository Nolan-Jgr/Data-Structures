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
void reverse(unsigned int x[], int n);

int main() {
    cout << "1. Read five positive integers\n2. Print array before reversal\n3. Print array after reversal\n4. Quit" << endl;
    int input;
    cin >> input;
    cout << endl;
    unsigned int numbers[5];
    do{
        switch(input)
        {
            case 1:{
                cout << "Enter positive integers" << endl;
                {
                    for(int i = 0; i < 5;i++)
                    {
                        cin >> numbers[i];
                    }
                }
                cout << endl;

            }
            break;
            case 2:{
                cout << "Entered numbers before reversal: ";
                for(int i=0;i < 5;i++)
                {
                    cout << numbers[i] << " ";
                }
                cout << endl;
            }
            break;
            case 3:{
                cout << "Entered numbers after reversal: ";
                reverse(numbers,5);
                for(int i=0;i < 5;i++)
                {
                    cout << numbers[i] << " ";
                }
                cout << endl;
            }
            break;
            case 4:{
                break;
            }
            default:
                cout << "invalid input" << endl;
        }
        cout << "1. Read five positive integers\n2. Print array before reversal\n3. Print array after reversal\n4. Quit" << endl;
        cin >> input;
        cout << endl;
    }while(input != 4);

}
void reverse(unsigned int x[], int n)
{
    if(x[n] < 10)
    {
        reverse(x,n-1);
    }
    else
    {
        int temp = 0;
        while(x[n] > 0)
        {
            temp = (temp * 10) + (x[n] % 10);
            x[n] = x[n] / 10;
        }
        x[n] = temp;
        reverse(x,n-1);
    }
}

