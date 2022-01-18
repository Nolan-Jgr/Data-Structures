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
int countVowels(string s);

int main() {
    string menu = "1. Read input string\n2. Compute number of vowels\n3. Quit program";
    cout << menu << endl;
    int input;
    cin >> input;
    cout << endl;
    do{
        string str;
        switch(input)
        {
            case 1:{
                cout << "Enter a phrase(s) or word" << endl;
                getline(cin, str);
                cin.ignore();
                cout << endl;
            }
            break;
            case 2:{
                cout << "You entered string: " << str << endl;
                cout << "Number of vowels: " << countVowels(str) << endl;
            }
            break;
            case 3:{
                break;
            }
            default:
                cout << "invalid input" << endl;
        }
        cout << menu << endl;
        cin >> input;
        cout << endl;
    }while(input != 3);

}
int countVowels(string s)
{
    if(s.empty())
    {
        return 0;
    }
    if(s.substr(0,1) == "a" || s.substr(0,1) == "e" || s.substr(0,1) == "i" || s.substr(0,1) == "o" || s.substr(0,1) == "u")
    {
        return 1 + countVowels(s.substr(1,s.size()));
    }
    else
    {
        return countVowels(s.substr(1,s.size()));
    }
}