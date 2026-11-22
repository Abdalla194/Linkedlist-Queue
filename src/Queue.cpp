
#include "Queue.h"

#include <iostream>

#include "LinkedList.h"
using namespace std;
int Queue::activeStacksCount = 0;

int Queue::getactiveStacksCount() { return activeStacksCount; }

Queue::Queue(int sizeArray) : sizeArray(sizeArray), top(-1) {
  activeStacksCount++;
}

void Queue::push(int data) {
  if (top + 1 >= sizeArray) {
    cout << "Stack is full!" << endl;
    return;
  }

  items.push_back(data);
  top++;

  //   LOG("We Write index: " << top);
}

int Queue::pop() {
  if (top == -1) {
    cout << "Stack is empty!" << endl;
    return -1;
  }

  top--;

  return items.pop_back();
}

void Queue::display() { items.print(); }
// Stack& Stack::operator=(const Stack& s) {
// //   LOG("Assignment Operator ::");

//   if (this == &s) {
//     return *this;
//   }

//   delete items;

//   sizeArray = s.sizeArray;
//   top = s.top;

//   items = new Employees[sizeArray];

//   for (int i = 0; i <= top; i++) {
//     items[i] = s.items[i];
//   }

//   return *this;
// }
Queue::~Queue() { activeStacksCount--; }
// Stack::~Stack() {
// //   LOG("Destructor");

//   activeStacksCount--;

//   delete items;
// }
