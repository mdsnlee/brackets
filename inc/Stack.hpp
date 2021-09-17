
#pragma once
#include "LinkedList.hpp"


class Stack
{
private:
    LinkedList *_list;
    int _size;

public:
    Stack()
    {
        _list = new LinkedList();        
    }
        ~Stack()
    {
        delete _list;
    }

    

    void push(void *val)
    {
        _list->addHead(val);
        _size++;
    }

    void* pop()
    {
        void* val = nullptr;
        if(!isEmpty())
        {
            val = _list->getHead()->value;
            _list->deleteHead();
            _size--;
        }
        return val;
    }

    bool isEmpty()
    {
        return _size == 0;
    }

};

//3 basic functions
//push adds to linked list
//pop takes it out of the linked is
//isempty 