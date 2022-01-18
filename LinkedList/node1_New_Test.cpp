//Name:         Nolan Jaeger
//Class:        CS 3305
//Term:         Spring 2021
//Instructor:   Dr.Haddad
//Assignment:   5
#include <iostream>
#include "node1_New.h"
#include "node1_New.cpp"
#include <cstdlib>
#include <cassert>    // Provides assert

using namespace std;
using namespace main_savitch_5;
void DisplayMenu();
void printList(node*& test);

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
                assert(list_length(head_ptr) >=1);
                cout << "where would you like to input the grade?(enter index)" << endl;
                cin >> index;
                cout << endl;
                assert(index <= list_length(head_ptr));
                cout << "what is the grade?" << endl;
                double x;
                cin >> x;
                cout << endl;
                if(index == 0 && head_ptr->data() == 0)
                {
                    head_ptr->set_data(x);
                }
                else if(index == 0)
                {
                    list_head_insert(head_ptr,x);
                }
                else
                {
                    node* temp = list_locate(head_ptr,index);
                    list_insert(temp,x);
                }
            }
                break;
            case 1:{
                cout << "what grade would you like to remove?(enter index)" << endl;
                cin >> index;
                cout << endl;
                assert(list_length(head_ptr) >= 1 && index < list_length(head_ptr));
                if(index == 0)
                {
                    list_head_remove(head_ptr);
                }
                else if(index-1 == 0)
                {
                    list_remove(head_ptr);
                }
                else
                {
                    list_remove(list_locate(head_ptr,index-1));
                }

            }
                break;
            case 2:{
                list_clear(head_ptr);
                cout << "list cleared" << endl;
                head_ptr = new node();

            }
                break;
            case 3:{
                cout << "What grade would you like to change?" << endl;
                double x;
                cin >> x;
                cout << endl;
                node *temp;
                temp = list_search(head_ptr, x);
                cout << "what would you like to change the grade to?" << endl;
                cin >> x;
                temp->set_data(x);
            }
                break;
            case 4:{
                printList(head_ptr);
            }
                break;
            case 5:{
                node* head_ptr2 = new node();
                head_ptr2 = delete_reps(head_ptr);
                cout << "list without repeats is:" << endl;
                printList(head_ptr2);
            }
                break;
            case 6:{
                sort_list(head_ptr);
                cout << "sorted list is:" << endl;
                printList(head_ptr);
            }
                break;
            case 7:{
                cout << "Enter grade to stop at" << endl;
                double stop;
                cin >> stop;
                cout << endl;
                node* first = new node();
                split_list(head_ptr,first,stop);
                cout << "first part: " << endl;
                printList(head_ptr);
                cout << "second part: " << endl;
                printList(first);
            }
                break;
            case 8:{
                break;
            }
            default:
                cout << "invalid input" << endl;

        }

    }while(input != 8);

    return (EXIT_SUCCESS);

}

void DisplayMenu() //creates menu
{
    cout << "What would you like to do?" << endl;
    cout << "0. ADD A GRADE" << endl;
    cout << "1. REMOVE A GRADE" << endl;
    cout << "2. CLEAR THE LIST" << endl;
    cout << "3. CHANGE A GRADE" << endl;
    cout << "4. VIEW GRADES" << endl;
    cout << "5. DELETE REPLICATES" << endl;
    cout << "6. SORT LIST" << endl;
    cout << "7. SPLIT LIST" << endl;
    cout << "8. QUIT" << endl;
}
void printList(node*& test)
{
    for(node* temp = test; temp != NULL; temp = temp->link())
    {
        if(list_length(test) == 1)
        {
            cout << temp->data();
        }
        else
        {
            cout << temp->data() << " ";
        }
    }
    cout << endl;
}
