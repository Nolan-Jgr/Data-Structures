//Name: Nolan Jaeger 
//Class: CS 3305
//Term: Spring 2021
//Instructor: Dr. Haddad
//Assignment: 9
#include <string>
#include <iostream>
#include <algorithm>
#include "bst.h"
using namespace std;
void printData(string str);

int main(){
    binary_search_tree<string> bst;
    string *test;
    int size = 1;
    cout << "Input strings(-1 to stop)" << endl;
    string input;
    cin >> input;
    test = new string[size];
    size++;
    while(input != "-1")
    {
       bst.insert(input);
       string *temp = new string[size];
       for(int i = 0; i < size-1;i++)
       {
           temp[i] = test[i];
       }
       temp[size-1] = input;
       test = temp;
       size++;
        cin >> input;

    }
    cout << "Original Text: ";
    for(int i = 0; i < size-1;i++)
    {
        cout << test[i] << " ";
    }
    cout << endl;
    cout << "Processed Text: ";
    inorder(printData,bst.get_root());
    cout << endl;
    return EXIT_SUCCESS;
}
void printData(string str)
{
    cout << str << " ";
}