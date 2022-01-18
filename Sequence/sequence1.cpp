//Name:         Nolan Jaeger
//Class:        CS 3305
//Term:         Spring 2021
//Instructor:   Dr.Haddad
//Assignment:   3
#include <algorithm>    // Provides copy function
#include <cassert>      // Provides assert function
#include <iostream>
#include "sequence1.h"

using namespace std;

namespace main_savitch_3
{
    // CONSTRUCTOR
    sequence::sequence()
    {
        used = 0; //Sequence is initialized and set to empty
    }
    // MODIFICATION MEMBER FUNCTIONS
    void sequence::start()
    {
        if(size()>0)
            current_index = 0; //first item is now the current item
    }
    void sequence::advance()
    {
        if(is_item()) {
            current_index++; //Sets the current index to the next item index
        }
    }
    void sequence::insert(const value_type& entry)
    {
        // Library facilities used: cassert
        assert( size() < CAPACITY);
        if(!is_item()) {
            current_index = 0;
        }
        for(size_type i = used; i>current_index; i--)
            data[i] = data[i-1]; //Shifts all entries the right
        data[current_index] = entry; //Inserts the entry into the current index
        used++; //increases the size of the sequence
    }
    void sequence::attach(const value_type& entry)
    {
        // Library facilities used: cassert
        assert( size() < CAPACITY);
        if(!is_item())
        {current_index= used-1;
        current_index++; //sets current index to the sequence size
        }
        for(size_type i = used; i>current_index; i--)
            data[i] = data[i-1]; //shifts all entries to the right
        data[current_index] = entry; //sets the entry to the current index //after the previous current index
        used++; //increases the size of the sequence
    }
    void sequence::remove_current()
    {
        if( is_item() ) {
            for(size_type i = current_index; i<used-1; i++) {
                data[i] = data[i+1]; //shifts all entries to the right
            }
            used--; //decreases the size of the sequence
        }
    }
    void sequence::display()
    {
        if(is_item())
        {
            for(size_type i = 0;i<used-1;i++)
            {
                cout << data[i] << " ";
            }
        }
    }
    // CONSTANT MEMBER FUNCTIONS
    sequence::size_type sequence::size() const
    {
        return used;
    }

    bool sequence::is_item() const
    {
        return (current_index >=0 && current_index < used);
    }

    sequence::value_type sequence::current() const
    {
        if( is_item() )
            return data[current_index];
    }

}