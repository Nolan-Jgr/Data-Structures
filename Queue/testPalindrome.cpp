#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
void charPalindrome();
void strPalindrome();

int main() {
    cout << "select option:\n1. Test character-by-character palindrome\n2. Test word-by-word palindrome\n3. Quit " << endl;
    unsigned int opt;
    cin >> opt;
    cout << endl;
    do{
        switch(opt)
        {
            case 1:
            {
                queue<char> q;
                stack<char> s;
                char letter;
                string input = "";
                queue<char>::size_type mismatches = 0; // Mismatches between queue and stack
                cout << "Enter a line and I will see if it's a palindrome:" << endl;
                while (cin.peek( ) != '\n')
                {
                    cin >> letter;
                    if(letter == ' ')
                    {
                        input += " ";
                    }
                    else{
                    input += letter;
                    }
                    if (isalpha(letter))
                    {
                        q.push(toupper(letter));
                        s.push(toupper(letter));
                    }
                }
                while ((!q.empty( )) && (!s.empty( )))
                {
                    if (q.front( ) != s.top( ))
                        ++mismatches;
                    q.pop( );
                    s.pop( );
                }
                cout << "You selected: Option 1" << endl;
                cout << "You entered: " << input << endl;
                if (mismatches == 0)
                    cout << "Judgement: palindrome." << endl;
                else
                    cout << "Judgement: not a palindrome." << endl;
            }
            break;
            case 2:
            {
                queue<string> q;
                stack<string> s;
                string str;
                string input = "";
                queue<string>::size_type mismatches = 0; // Mismatches between queue and stack
                cout << "Enter a line and I will see if it's a palindrome:" << endl;
                while (cin.peek( ) != '\n')
                {
                    cin >> str;
                    if(str == " ")
                    {
                        input += " ";
                    }
                    else {
                        input += str;
                    }
                    transform(str.begin(), str.end(), str.begin(), ::toupper);
                    q.push(str);
                    s.push(str);

                }
                while ((!q.empty( )) && (!s.empty( )))
                {
                    if (q.front( ) != s.top( ))
                        ++mismatches;
                    q.pop( );
                    s.pop( );
                }
                cout << "You selected: Option 2" << endl;
                cout << "You entered: " << input << endl;
                if (mismatches == 0)
                    cout << "Judgement: palindrome." << endl;
                else
                    cout << "Judgement: not a palindrome." << endl;
            }
            break;
            case 3:
            {
                break;
            }
            default:
                cout << "invalid input" << endl;
        }
        cout << "select option:\n1. Test character-by-character palindrome\n2. Test word-by-word palindrome\n3. Quit " << endl;
        cin >> opt;
        cout << endl;
    }while(opt != 3);

}
void charPalindrome()
{
    queue<char> q;
    stack<char> s;
    char letter;
    string input = "";
    queue<char>::size_type mismatches = 0; // Mismatches between queue and stack
    cout << "Enter a line and I will see if it's a palindrome:" << endl;
    while (cin.peek( ) != '\n')
    {
        cin >> letter;
        input += letter;
        if (isalpha(letter))
        {
            q.push(toupper(letter));
            s.push(toupper(letter));
        }
    }
    while ((!q.empty( )) && (!s.empty( )))
    {
        if (q.front( ) != s.top( ))
            ++mismatches;
        q.pop( );
        s.pop( );
    }
    cout << "You selected: Option 1" << endl;
    cout << "You entered: " << input << endl;
    if (mismatches == 0)
        cout << "Judgement: palindrome." << endl;
    else
        cout << "Judgement: not a palindrome." << endl;
}
void strPalindrome()
{
    queue<string> q;
    stack<string> s;
    string str;
    string input = "";
    queue<string>::size_type mismatches = 0; // Mismatches between queue and stack
    cout << "Enter a line and I will see if it's a palindrome:" << endl;
    while (cin.peek( ) != '\n')
    {
        cin >> str;
        input += str;
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        q.push(str);
        s.push(str);

    }
    while ((!q.empty( )) && (!s.empty( )))
    {
        if (q.front( ) != s.top( ))
            ++mismatches;
        q.pop( );
        s.pop( );
    }
    cout << "You selected: Option 2" << endl;
    cout << "You entered: " << input << endl;
    if (mismatches == 0)
        cout << "Judgement: palindrome." << endl;
    else
        cout << "Judgement: not a palindrome." << endl;
}