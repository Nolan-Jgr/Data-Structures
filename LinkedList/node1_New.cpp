//Name:         Nolan Jaeger
//Class:        CS 3305
//Term:         Spring 2021
//Instructor:   Dr.Haddad
//Assignment:   5
// FILE: node1.cxx
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include "node1_New.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
using namespace std;

namespace main_savitch_5
{
    size_t list_length(const node* head_ptr)
    // Library facilities used: cstdlib
    {
        const node *cursor;
        size_t answer;

        answer = 0;
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
            ++answer;

        return answer;
    }

    void list_head_insert(node*& head_ptr, const node::value_type& entry)
    {
        head_ptr = new node(entry, head_ptr);
    }

    void list_insert(node* previous_ptr, const node::value_type& entry)
    {
        node *insert_ptr;

        insert_ptr = new node(entry, previous_ptr->link( ));
        previous_ptr->set_link(insert_ptr);
    }

    node* list_search(node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
        node *cursor;

        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
            if (target == cursor->data( ))
                return cursor;
        return NULL;
    }

    const node* list_search(const node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
        const node *cursor;

        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
            if (target == cursor->data( ))
                return cursor;
        return NULL;
    }

    node* list_locate(node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
        node *cursor;
        size_t i;

        assert (0 < position);
        cursor = head_ptr;
        for (i = 1; (i < position) && (cursor != NULL); i++)
            cursor = cursor->link( );
        return cursor;
    }

    const node* list_locate(const node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
        const node *cursor;
        size_t i;

        assert (0 < position);
        cursor = head_ptr;
        for (i = 1; (i < position) && (cursor != NULL); i++)
            cursor = cursor->link( );
        return cursor;
    }

    void list_head_remove(node*& head_ptr)
    {
        node *remove_ptr;

        remove_ptr = head_ptr;
        head_ptr = head_ptr->link( );
        delete remove_ptr;
    }

    void list_remove(node* previous_ptr)
    {
        node *remove_ptr;

        remove_ptr = previous_ptr->link( );
        previous_ptr->set_link( remove_ptr->link( ) );
        delete remove_ptr;
    }

    void list_clear(node*& head_ptr)
    // Library facilities used: cstdlib
    {
        while (head_ptr != NULL)
            list_head_remove(head_ptr);
    }

    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
    // Library facilities used: cstdlib
    {
        head_ptr = NULL;
        tail_ptr = NULL;

        // Handle the case of the empty list.
        if (source_ptr == NULL)
            return;

        // Make the head node for the newly created list, and put data in it.
        list_head_insert(head_ptr, source_ptr->data( ));
        tail_ptr = head_ptr;

        // Copy the rest of the nodes one at a time, adding at the tail of new list.
        source_ptr = source_ptr->link( );
        while (source_ptr != NULL)
        {
            list_insert(tail_ptr, source_ptr->data( ));
            tail_ptr = tail_ptr->link( );
            source_ptr = source_ptr->link( );
        }
    }
    node* delete_reps(node* head_ptr)
    {
        node* head_ptr2 = new node();
        node* z = head_ptr2;
        for(node* x = head_ptr;x != NULL;x = x->link())
        {
            if(head_ptr2->data()==0)
            {
                head_ptr2->set_data(x->data());
                x =x->link();
            }
            double value = x->data();
            bool isIn = false;
            for(node* y = head_ptr2; y!=NULL;y = y->link())
            {
                if(y->data() == value)
                {
                    isIn = true;
                }
            }
            if(isIn == false)
            {
                list_insert(z,value);
                z = z->link();
            }

        }
        return head_ptr2;
    }
    void sort_list(node*& head_ptr)
    {
        node* x = head_ptr;
        while (x) {
            node* min = x;
            node* r = x->link();


            while (r) {
                if (min->data() > r->data())
                    min = r;

                r = r->link();
            }
            double temp = x->data();
            x->set_data(min->data());
            min->set_data(temp);
            x = x->link();
        }
    }
    void split_list(node*& head_ptr,node*& head_ptr2,const node::value_type& entry)
    {
        if(head_ptr->data() == entry)
        {
            return;
        }
        else if(list_length(head_ptr) == 2)
        {
            node* original = head_ptr;
            node* current = head_ptr->link();
            head_ptr2 = current;
            original->set_link(NULL);
        }
        else{
            node* original = head_ptr;
            node* current = list_search(head_ptr,entry);
            head_ptr2 = current;

            while (original->link()->data() != entry)
            {
                original = original->link();
            }
            original->set_link(NULL);}
    }
}