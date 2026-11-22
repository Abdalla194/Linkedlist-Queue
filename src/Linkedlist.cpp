#include "LinkedList.h"

#include <iostream>
using namespace std;
LinkedList::LinkedList() {
  head = nullptr;
  tail = nullptr;
  count = 0;
}

LinkedList::~LinkedList() {
  Node* temp = head;

  while (temp != nullptr) {
    Node* next = temp->next;
    delete temp;
    temp = next;
  }

  head = nullptr;
  tail = nullptr;
  count = 0;
}

void LinkedList::push_back(int value) {
  Node* newNode = new Node(value);

  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }

  count++;
}
int LinkedList::pop_back() {
  if (head == nullptr) {
        cout << "Queue is empty!" << endl;
        return -1;
    }

    Node* temp = head;
    int data = head->data;

    head = head->next;

    delete temp;
    count--;

    if (head == nullptr)
        tail = nullptr;

    return data;
}

void LinkedList::InsertAfter(int data, int afterData) {
  Node* temp = head;

  while (temp != nullptr && temp->data != afterData) temp = temp->next;

  if (temp == nullptr) return;

  Node* newNode = new Node(data);

  newNode->next = temp->next;
  temp->next = newNode;

  if (temp == tail) tail = newNode;

  count++;
}

void LinkedList::InsertBefore(int data, int beforeData) {
  if (head == nullptr) return;
  if (head->data == beforeData) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    count++;
    return;
  }

  Node* temp = head;

  while (temp->next != nullptr && temp->next->data != beforeData) {
    temp = temp->next;
  }

  if (temp->next == nullptr) return;

  Node* newNode = new Node(data);

  newNode->next = temp->next;
  temp->next = newNode;

  count++;
}

int LinkedList::GetCount() { return count; }

int LinkedList::GetDataByIndex(int index) {
  if (index < 0 || index >= count) return -1;

  Node* temp = head;

  for (int i = 0; i < index; i++) temp = temp->next;

  return temp->data;
}
void LinkedList::print() {
  Node* temp = head;

  while (temp != nullptr) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
}

Node* LinkedList::get_head() const { return head; }
