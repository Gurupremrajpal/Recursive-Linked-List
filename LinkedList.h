/**
This is base code for Homework 09 for CST238 Fall 2019
Sections 2 & 3
It does not need to be modified or turned in
*/
#include<iostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class Node {
public:
    Node();
    Node(int data);
    Node(const Node & source);
    ~Node();
    Node * getNext() const { return myNext; };
    bool hasNext() const;
    void append(int data);
    bool insertAfter(int oldData, int newData);
    bool removeNext(int data);
    int getData () const { return myData; };
    void display() const;
    bool search(int data) const;
private:
    int myData;
    Node * myNext;
    void setNext(Node * next);
};

class LinkedList {
public:
    LinkedList();
    LinkedList(const LinkedList & source);
    ~LinkedList();
    LinkedList operator=(const LinkedList & source);
    Node * getFirst() const { return myFirst; };
    bool empty() const;
    bool insertAfter(int oldData, int newData);
    bool remove(int oldData);
    void append(int data);
    void display() const;
    bool search(int data) const;
private:
    Node * myFirst;
};


#endif


