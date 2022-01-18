//Name:         Nolan Jaeger
//Class:        CS 3305
//Term:         Spring 2021
//Instructor:   Dr.Haddad
//Assignment:   4
#include "poly1.h"
#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;
namespace main_savitch_3
{
polynomial::polynomial() {
    cout << "enter size" << endl;
    size_t size;
    cin >> size;
    cout<<endl;
    current_array_size = size;
    coef = new double[current_array_size];
    for(int i = 0; i < current_array_size; i++)
    {
        coef[i] = 0.0;
    }
}
polynomial::polynomial(double a0) {
    current_array_size = 1;
    coef = new double[current_array_size];
    coef[0] = a0;
}
polynomial::polynomial(const polynomial &source) {
    coef = new double[source.current_array_size];
    for(int i = 0; i < source.current_array_size; i++)
    {
        coef[i] = source.coefficient(i);
    }
}
polynomial::~polynomial() {
    delete [] coef;
}
void polynomial::add_to_coef(double amount, unsigned int k) {
    coef[k] = coef[k] + amount;
}
void polynomial::assign_coef(double coefficient, unsigned int k) {
    if(k > current_array_size)
    {
        current_array_size = current_array_size + k;
    }
    coef[k] = coefficient;
    /*if(k >= current_array_size)
    {
        double *new_coef = new double[current_array_size + k];

        for(int i = 0 ; i < current_array_size ; i++)
        {
            *(new_coef + i) = *(coef + i);
        }

        current_array_size = k + current_array_size;

        delete [] coef;
        coef = new_coef;
    }*/
}
void polynomial::clear() {
    for(int i = 0; i < current_array_size;i++)
    {
        coef[i] = 0.0;
    }
}
void polynomial::reserve(size_t number) {

    current_array_size = number;
}
polynomial& polynomial::operator = (const polynomial& source ){
    if(this == &source)
    {
        return *this;
    }
    else
    {
        for(int i=0; i < source.current_array_size;i++)
        {
            coef[i] = source.coefficient(i);
        }
    }
    return *this;
}
double polynomial::coefficient(unsigned int k) const {
    if(k > current_array_size || k < 0) {
        return 0;
    }
    else
    {
        return coef[k];
    }

}
unsigned int polynomial::degree() const {
    bool x = true;
    int ans = 0;
    while(x)
    {
        for(int i = 0; i < current_array_size;i++)
        {
            if(coef[i] > 0)
            {
                ans = i;
                x = false;
            }
        }
        if(x)
        {
            return current_array_size-1;
        }
    }

    /*int x = 0;
    for(int i = 0; i < current_array_size; i++)
    {
        if(coef[i] > 0)
        {
            x = i;
        }
    }
    return x;*/
}
unsigned int polynomial::next_term(unsigned int k) const {
    int x = k;
    for(int i = k;i < current_array_size;i++)
    {
        if(coef[i] > 0)
        {
            x = i;
        }
    }
    return x;
}
double polynomial::eval(double x) const {
    double output = 0.0;
    for(int i = 0; i < sizeof(coef);i++)
    {
        output += coef[i] * pow(x,i);
    }
    return output;
}
polynomial operator- (const polynomial& p1, const polynomial& p2)
{
    polynomial answer(p1);
    answer = answer - p2;
    return answer;
}
polynomial operator+ (const polynomial& p1, const polynomial& p2)
{
    polynomial answer(p1);
    answer = answer + p2;
    return answer;
}

}

