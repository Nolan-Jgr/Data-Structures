//Name:         Nolan Jaeger
//Class:        CS 3305
//Term:         Spring 2021
//Instructor:   Dr.Haddad
//Assignment:   5
#include <iostream>
#include "node1.h"
#include "node1.cpp"
#include <cstdlib>
#include <cassert>    // Provides assert

using namespace std;
using namespace main_savitch_5;
void DisplayMenu();
void head_insert(node*& test);
void insert(node*& test);
void search(node*& test);
void locate(node*& test);
void head_remove(node*& test);
void remove(node*& test);
void clear(node*& test);
void displayList(node*& test);

int main() {
    node* head_ptr = new node();


    unsigned int input;
    do{
        DisplayMenu();
        cin >> input;
        cout << endl;

        unsigned int index;
        switch(input)
        {
            case 0:{
                head_insert(head_ptr);}
                break;
            case 1:{
                insert(head_ptr);}
                break;
            case 2:{
                search(head_ptr);}
                break;
            case 3:{
                locate(head_ptr);}
                break;
            case 4:{
                head_remove(head_ptr);}
                break;
            case 5:{
                remove(head_ptr);}
                break;
            case 6:{
                clear(head_ptr);}
                break;
            case 7:
            {
                node* head_ptr2 = new node();
                node* tail_ptr2 = head_ptr2->link();
                list_copy(head_ptr,head_ptr2,tail_ptr2);}
                break;
            default:
            {
                cout << "invalid input" << endl;
            }


        }

    }while(input != 8);

    return (EXIT_SUCCESS);

}

void DisplayMenu() //creates menu
{
    cout << "What would you like to do?" << endl;
    cout << "0. head_insert" << endl;
    cout << "1. regular insert" << endl;
    cout << "2. search for a grade" << endl;
    cout << "3. locate a grade at index" << endl;
    cout << "4. remove_head" << endl;
    cout << "5. regular remove" << endl;
    cout << "6. clear list" << endl;
    cout << "7. copy list" << endl;
    cout << "8.Quit" << endl;
}
void head_insert(node*& test)
{
    assert(list_length(test) >=1);
    cout << "what is the grade?" << endl;
    double x;
    cin >> x;
    cout << endl;
    if(test->data() == 0)
    {
        test->set_data(x);
    }
    else
    {
        list_head_insert(test,x);
    }
    displayList(test);
}
void insert(node*& test)
{
    assert(list_length(test) >=1);
    unsigned int index;
    cout << "where would you like to input the grade?(enter index)" << endl;
    cin >> index;
    cout << endl;
    assert(index <= list_length(test));
    cout << "what is the grade?" << endl;
    double x;
    cin >> x;
    cout << endl;
    node* temp = list_locate(test,index);
    list_insert(temp,x);
    displayList(test);
}
void search(node*& test)
{
    cout << "what is the grade you would like to search for?"<<endl;
    double s;
    cin >> s;
    node* temp = list_search(test,s);
    list_search(test, s);
    if(temp == NULL)
    {
        cout << "grade is not in list" << endl;
    }
    else
    {
        cout << "grade " << test->data() << " was found" << endl;
    }
    displayList(test);
}
void locate(node*& test)
{
    cout << "Enter the index of the grade you want to locate" << endl;
    unsigned int index;
    cin >> index;
    node* temp = list_locate(test,index);
    if(index >= list_length(test))
    {
        cout << "invalid input"<<endl;
    }
    else
    {
        cout << "grade " << test->data() << " at index " << index << " was found" << endl;
    }
    displayList(test);
}
void head_remove(node*& test)
{
    list_head_remove(test);
    displayList(test);
}
void remove(node*& test)
{
    cout << "what grade would you like to remove?(enter index)" << endl;
    unsigned int index;
    cin >> index;
    cout << endl;
    assert(list_length(test) >= 1 && index < list_length(test));
    if(index-1 == 0)
    {
        list_remove(test);
    }
    else
    {
        list_remove(list_locate(test,index-1));
    }
    displayList(test);
}
void clear(node*& test)
{
    list_clear(test);
    cout << "list cleared" << endl;
    displayList(test);
}
void displayList(node*& test)
{
    assert(list_length(test) != 0);
    if(list_length(test) == 1)
    {
        cout << test->data() << endl;
    }
    else {
        for (node *temp = test; test != NULL; test = test->link()) {
            cout << temp->data() << " " << endl;
        }
    }
}

