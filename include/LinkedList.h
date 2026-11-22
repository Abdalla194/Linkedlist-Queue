#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int count;

public:
    LinkedList();
    LinkedList(const LinkedList& ls);
    ~LinkedList();

    LinkedList& operator=(const LinkedList& ls);

    void push_back(int value);
    int pop_back();

    void InsertAfter(int data, int afterData);
    void InsertBefore(int data, int beforeData);

    int GetCount();
    int GetDataByIndex(int index);

    void print();
    Node* get_head() const;
};

#endif