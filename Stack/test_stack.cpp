#include <iostream>
#include <cstdlib>
#include <cassert>
#include <stack>
using namespace std;
void topToBottom(stack<int> x);
void bottomToTop(stack<double> y);
stack<string> flipStack(stack<string> z);
bool searchStack(stack<int> a,int n);
bool checkIfPalindrome(stack<char> b);
void displayMenu();
int main() {
    int input;
    do{
        displayMenu();
        cin >> input;
        cout << endl;

        switch(input)
        {
            case 1:{
                stack<int> test;
                cout << "Please enter test data(enter -1 to stop)" << endl;
                int data;
                cin >> data;
                while(data >= 0)
                {
                    test.push(data);
                    cin >> data;
                }
                stack<int> temp = test;
                cout << "Testing Function topToBottom:" << endl;
                cout << "Stack Content: ";
                while(!temp.empty())
                {
                    cout << temp.top() <<  " ";
                    temp.pop();
                }
                cout << endl;
                cout << "Function Contents: ";
                topToBottom(test);
            }
                break;
            case 2:{
                stack<double> test;
                cout << "Please enter test data(enter -1 to stop)" << endl;
                double data;
                cin >> data;
                while(data >= 0)
                {
                    test.push(data);
                    cin >> data;
                }
                stack<double> temp = test;
                cout << "Stack Content: ";
                while(!temp.empty())
                {
                    cout << temp.top() <<  " ";
                    temp.pop();
                }
                cout << endl;
                cout << "Function Contents: ";
                bottomToTop(test);
            }
                break;
            case 3:{
                stack<string> test;
                cout << "Please enter test data(enter ! to stop)" << endl;
                string data;
                cin >> data;
                while(data != "!")
                {
                    test.push(data);
                    cin >> data;
                }
                stack<string> temp = test;
                cout << "Before: ";
                while(!temp.empty())
                {
                    cout << temp.top() <<  " ";
                    temp.pop();
                }
                cout << endl;
                test = flipStack(test);
                cout << "After: ";
                stack<string> temp2 = test;
                while(!temp2.empty())
                {
                    cout << temp2.top() <<  " ";
                    temp2.pop();
                }
                cout << endl;
            }
                break;
            case 4:{
                stack<int> test;
                cout << "Please enter test data(enter -1 to stop)" << endl;
                int data;
                cin >> data;
                while(data >= 0)
                {
                    test.push(data);
                    cin >> data;
                }
                cout << "Enter number to search for: " << endl;
                int num;
                cin >> num;
                stack<int> temp = test;
                cout << "Stack Content: ";
                while(!temp.empty())
                {
                    cout << temp.top() <<  " ";
                    temp.pop();
                }
                cout << endl;
                cout << "Target Value: " << num << endl;
                if(searchStack(test,num))
                {
                    cout << "Function Output: " << "true" << endl;
                }
                else
                {
                    cout << "Function Output: " << "false" << endl;
                }
            }
                break;
            case 5:{
                stack<char> test;
                cout << "Please enter test data(enter ! to stop)" << endl;
                char data;
                cin >> data;
                while(data != '!')
                {
                    test.push(data);
                    cin >> data;
                }
                stack<char> temp = test;
                cout << "Stack Content: ";
                while(!temp.empty())
                {
                    cout << temp.top() <<  " ";
                    temp.pop();
                }
                cout << endl;
                if(checkIfPalindrome(test))
                {
                    cout << "Function output: " << "true" << endl;
                }
                else
                {
                    cout << "Function output: " << "false" << endl;
                }
            }
                break;
            case 6:
                break;
            default:
                cout << "Invalid input" << endl;

        }

    }while(input != 6);

    return (EXIT_SUCCESS);



}
void displayMenu()
{
    cout << "what would you like to do?" << endl;
    cout << "1. topToBottom" << endl;
    cout << "2. bottomToTop" << endl;
    cout << "3. flipStack" << endl;
    cout << "4. searchStack" << endl;
    cout << "5. checkIfPalindrome" << endl;
    cout << "6. QUIT" << endl;
}


void topToBottom(stack<int> x)
{
    stack<int> temp = x;
    while(!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

void bottomToTop(stack<double> y)
{
    stack<double> temp = y;
    stack<double> temp2;
    while(!temp.empty())
    {
        temp2.push(temp.top());
        temp.pop();
    }
    while(!temp2.empty())
    {
        cout << temp2.top() << " ";
        temp2.pop();
    }
    cout << endl;
}

stack<string> flipStack(stack<string> z)
{
    stack<string> temp;
    while(!z.empty())
    {
        temp.push(z.top());
        z.pop();
    }
    return temp;
}

bool searchStack(stack<int> a,int n)
{
    stack<int> temp = a;
    int temp2;
    while(!temp.empty())
    {
        temp2 = temp.top();
        if(temp2 == n)
        {
            return true;
        }
        temp.pop();
    }
    return false;
}

bool checkIfPalindrome(stack<char> b)
{
    stack<char> temp = b;
    stack<char> reverse;
    stack<char> temp2 = b;
    while(!temp.empty())
    {
        reverse.push(temp.top());
        temp.pop();
    }
    while(!temp2.empty())
    {
        char c = temp2.top();
        char d = reverse.top();
        if(c != d)
        {
            return false;
        }
    }
    return true;
}




