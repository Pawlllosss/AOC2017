#include "List.h"
#include <iostream>

List * List::_root = 0;
int List::_items_count = 0;

List::~List()
{
    if( _next != _root )
        delete _next;
}


void List::Add(const int value)
{
    if( _items_count == 0)
    {
        _number = value;
        _root = this;
        _next = this;
    }
    else
    {
        List * list_iterator = this;

        while( list_iterator->_next != _root)
            list_iterator = list_iterator->_next;

        List * node_to_add = new List;

        node_to_add->_next = _root;
        node_to_add->_number = value;

        list_iterator->_next = node_to_add;

    }

    _items_count++;
}

void List::Print() const
{
    const List * list_iterator = this;

    while( list_iterator->_next != _root)
        {
        std::cout<<list_iterator->_number<<std::endl;
        list_iterator = list_iterator->_next;
        }

    std::cout<<list_iterator->_number<<std::endl<<std::endl;
}

int List::Calculate()
{
    int sum = 0;

    bool flag = 1; //is the root being checked at the moment?

    List * list_iterator = _root; //it checks whole list
    List * node_to_match; //it check a node _items_count/2 from the one pointed by the list-iterator at the moment

    //assumption:list will always have an even number of nodes

    while( flag )
    {
        if( list_iterator->_next == _root  )
            flag = 0;

        node_to_match = list_iterator;

        for( int i = 0 ; i < _items_count/2 ; i++ )
            node_to_match = node_to_match->_next;

        if( list_iterator->_number == node_to_match->_number )
            sum += node_to_match->_number;

        list_iterator = list_iterator->_next;
    }

    return sum;
}
