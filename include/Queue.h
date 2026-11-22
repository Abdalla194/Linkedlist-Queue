#ifndef Queue_h
#define Queue_h

#include "LinkedList.h"

class Queue {
private:
    static int activeStacksCount;

    int top;
    int sizeArray;
    LinkedList items;

public:
    Queue(int sizeArray);

    Queue(const Queue& s);
    // Stack& operator=(const Stack& s);

    ~Queue();

    void push(int data);
    int pop();
    void display();

    static int getactiveStacksCount();
};

#endif