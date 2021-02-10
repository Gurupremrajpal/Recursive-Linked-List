/**
This is base code for Homework 09 for CST238 Fall 2019
Sections 2 & 3
This file DOES need to be modified and handed in
ONLY RECURSION can be used; any iteration will result
in a zero for the assignment
*/


/*
* Title: project-2.cpp
 * Abstract: Recursive Linked List
 * Author: Guruprem Singh Rajpal
 * Email: grajpal@csumb.edu
 * Estimate: 12 hours
 * Date: 05/03/2020
*/


#include <iostream>
#include "LinkedList.h"
using namespace std;
/**
* Implement these functions IN ORDER
*/

// implement these two first
bool Node::hasNext() const {
    return myNext!=NULL;
}

bool LinkedList::empty() const 
{
  return myFirst == NULL;
}

// then these two
void Node::display() const 
{
  if(hasNext())
  {
    cout << myData << " ";
    myNext->display();
  }
  else
  {
    cout << myData << endl;
  }
}

void LinkedList::display() const 
{
  if(empty())
  {
    cout << "Empty!" << endl;
    return;
  }
  myFirst->display();
}

// then these two
// only append if this is the last node
// otherwise, recurse
void Node::append(int data) 
{
  if(hasNext())
  {
    myNext->append(data);
  }
  else
  {
    Node *n = new Node(data);
    myNext = n;
  }
}

void LinkedList::append(int data) {
  if(empty())
  {
    myFirst = new Node(data);
    return;
  }
  myFirst->append(data);
}

// then these two
bool Node::search(int data) const 
{
  if(hasNext())
  {
    return myData == data || myNext -> search(data);
  }
  else
  {
    return myData == data;
  }
}

bool LinkedList::search(int data) const 
{
  if(empty())
  {
    return false;
  }
  return myFirst -> search(data);
}

// then these two
bool Node::insertAfter(int oldData, int newData) 
{
  if(myData == oldData)
  {
    Node *n = new Node(newData);
    n->setNext(myNext);
    myNext = n;
    return true;
  }
  else if(hasNext())
  {
    return myData == oldData || myNext -> insertAfter(oldData, newData);
  }
  else
  {
    return false;
  }
}

bool LinkedList::insertAfter(int oldData, int newData) 
{
  if(empty() )
  return false;
  
  return myFirst->insertAfter(oldData, newData);
}

// then these two
bool Node::removeNext(int data) 
{
  if(hasNext())
  {
    if(myNext->myData == data)
    {
      myNext = myNext -> myNext;
      return true;
    }
    return myNext->removeNext(data);
  }
  return false;
}

bool LinkedList::remove(int data) 
{
  if(empty())
  {
    return false;
  }
  else if(myFirst->getData()==data)
  {
    myFirst = myFirst->getNext();
    return true;
  }
  return myFirst->removeNext(data);
}

// then these two
Node::~Node() 
{
  delete myNext;
  cout << "Node Deleted" << endl;
}

LinkedList::~LinkedList() 
{
  delete myFirst;
  cout << "Linked List Deleted" << endl;
}

// then these two
Node::Node(const Node & source) 
{
  myData = source.myData;
  if(source.hasNext())
  {
    myNext = new Node(*(source.myNext));
  }
  else
  {
    myNext = NULL;
  }
}

LinkedList::LinkedList(const LinkedList & source) 
{
  if(source.empty())
  {
    myFirst = NULL;
  }
  else
  {
    myFirst = new Node(*(source.myFirst));
  }
}

// then this one
LinkedList LinkedList::operator=(const LinkedList & source) 
{
  if(this != &source)
  {
    delete myFirst;
    myFirst = new Node(*(source.myFirst));
  }
  return * this;
}

/**
* Implement the functions above, shouldn't need to change anything below,
but look at this for good examples!
*/

Node::Node(int data) {
    myData = data;
}

void Node::setNext(Node * next) {
    myNext = next;
}

LinkedList::LinkedList() {
    myFirst = nullptr; 
}

