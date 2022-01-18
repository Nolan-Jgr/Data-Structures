//Name: Nolan Jaeger 
//Class: CS 3305
//Term: Spring 2021
//Instructor: Dr. Haddad
//Assignment: 9
#include <string>
#include <algorithm>
#include "bst.h"
using namespace std;
void BSTinsert(string s[],binary_search_tree<string> *b,int size);

int main(){
    	cout << endl << "==================== Test # 5 ==================" << endl;
        string data[] = {"After","Also","any","back","because","come","day","even","first","give","how","its","look","most","new","now","only","other","our","over","than","then","these","think","two","us","use","want","way","well","work"};
        
        binary_search_tree<string> *bst;
        bst = new binary_search_tree<string>;
        int length = sizeof(data) / sizeof(data[0]);
        std::sort(data,data + length);
        BSTinsert(data,bst,length);
        cout << *bst << endl;
        print(bst->get_root(),0);
        cout << endl << "balanced? " << bst->is_balanced()<< endl;
        bst->remove("now");
        print(bst->get_root(),0);
        cout << endl << "balanced? " << bst->is_balanced()<< endl;

        return EXIT_SUCCESS;
}
void BSTinsert(string s[],binary_search_tree<string> *b,int size){
    if(size == 1)
    {
        b->insert(s[0]);
    }
    else{
        b->insert(s[size/2]);
        string temp[size/2];
        for(int i = 0; i < size/2;i++)
        {
            temp[i] = s[i];
        }
        BSTinsert(temp,b,size/2);
        string temp2[size/2];
        int index = 0;
        for(int i = size/2+1;i<size;i++)
        {
            temp2[index] = s[i];
            index++;
        }
        BSTinsert(temp2,b,size/2);
    }
}