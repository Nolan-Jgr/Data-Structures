// Name: Nolan Jaeger 
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 10
#include "PQ_Heap.h"
#include <iostream>
#include <ctime>
#include <ctype.h>
#include <string>

using namespace std;

int main()
{
    string menu = "0. Enter queue type(int or string)\n1. Enqueue element\n2. Dequeue element\n3. Check is_Full\n4. Check is_Empty\n5. Print size\n6. Display front element\n7. Print queue elements\n8. Quit";
    cout << menu << endl;
    int input;
    cin >> input;
    while(input != 0)
    {
        cout << "must enter queue type" << endl;
        cout << menu << endl;
        cin >> input;
    }
    string type;
    cout << "Enter queue type(int or string)" << endl;
    cin >> type;
    assert((type == "int") || type == "string");
    if(type == "int")
    {
        priority_queue_heap<int> pq1;
        cout << menu << endl;
        cin >> input;
        do{
            switch(input)
            {
                case 1:{
                    cout << "Enter a value to add" << endl;
                    int val;
                    cin >> val;
                    pq1.enqueue(val);
                }break;
                case 2:{
                    if(pq1.is_empty()){
                        cout << "No removal" << endl;
                    }
                    else{
                    cout << "Value removed: " << pq1.dequeue() << endl;
                    }
                }break;
                case 3:{
                    if(pq1.is_full())
                    {
                        cout << "Queue is full" << endl;
                    }
                    else{
                        cout << "Queue is not full" <<  endl;
                    }
            
                }break;
                case 4:{
                    if(pq1.is_empty())
                    {
                        cout << "Queue is empty" << endl;
                    }
                    else{
                        cout << "Queue is not empty" << endl;
                    }
                
                }break;
                case 5:{
                    cout << "Queue size: " << pq1.size() << endl;
                
                }break;
                case 6:{
                    cout << "Front Element: " << pq1.front() << endl;
                
                }break;
                case 7:{
                    pq1.h.check_heap();
                    cout << endl;
                }break;
                case 8:{
                    return EXIT_SUCCESS;
                }
                default:{
                    cout << "Invalid input" << endl;
                }
            }
            cout << menu << endl;
            cin >> input;
        }while(input !=8);
        
    }
    if(type == "string")
    {
       priority_queue_heap<string> pq2;
        cout << menu << endl;
        cin >> input;
        do{
            switch(input)
            {
                case 1:{
                    cout << "Enter a value to add" << endl;
                    string val;
                    cin >> val;
                    pq2.enqueue(val);
                }break;
                case 2:{
                    if(pq2.is_empty())
                    {
                        cout << "No Removal" << endl;
                    }
                    else{
                    cout << "Value removed: " << pq2.dequeue() << endl;
                    }
                }break;
                case 3:{
                    if(pq2.is_full())
                    {
                        cout << "Queue is full" << endl;
                    }
                    else{
                        cout << "Queue is not full" <<  endl;
                    }
            
                }break;
                case 4:{
                    if(pq2.is_empty())
                    {
                        cout << "Queue is empty" << endl;
                    }
                    else{
                        cout << "Queue is not empty" << endl;
                    }
                
                }break;
                case 5:{
                    cout << "Queue size: " << pq2.size() << endl;
                
                }break;
                case 6:{
                    cout << "Front Element: " << pq2.front() << endl;
                
                }break;
                case 7:{
                    pq2.h.check_heap();
                    cout << endl;
                }break;
                case 8:{
                    return EXIT_SUCCESS;
                }
                default:{
                    cout << "Invalid input" << endl;
                }
            }
            cout << menu << endl;
            cin >> input;
        }while(input !=8);
         
    }
    
    return EXIT_SUCCESS;
}