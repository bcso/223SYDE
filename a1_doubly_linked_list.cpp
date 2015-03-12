#include "a1_doubly_linked_list.hpp"

#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

//Brian So, 20477254
//Kenny Lam, 20519190 

DoublyLinkedList::Node::Node(DataType data)
{
    value = data;
}

DoublyLinkedList::DoublyLinkedList()
{
    size_ = 0;
    head_ = NULL;
    tail_ = head_;
    
}


DoublyLinkedList::~DoublyLinkedList()
{
    // deletes all the nodes
    Node * current = head_;
    Node * deletenode = head_;
    for(int i = 0; i < size_; i++){
        deletenode = current -> next;
        delete deletenode;
        current = deletenode;
    }
    head_ = NULL;
    
}

unsigned int DoublyLinkedList::size() const
{
    return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
    return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
    //Check size of list for empty
    if (size_ == 0){
        return true;
    } else {
        return false;
    }
}

bool DoublyLinkedList::full() const
{
    //Check size of list for empty
    if (size_ == CAPACITY){
        return true;
    }
    return false;
    
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    Node * current = head_;
    Node * tailend = tail_;
    
    if(index > size_){// if index greater than size, return value of last element
        return tailend -> value;
    }
    
    for(int i= 0; i < index; i++){
        current = current -> next ;
    }
    return current->value;
}

unsigned int DoublyLinkedList::search(DataType value) const
{
    int i = 0;
    Node * current = head_;
    
    while( i < size_){
        if(value == current -> value){ //if value found, return index
            return i;
        }
        current = current -> next;
        i++;
    }
    
    return size_;
    
}

void DoublyLinkedList::print() const
{
    Node *temp = head_;
    int i =0;
    while(i < size_){
        cout<< temp -> value << endl; // print values
        temp = temp->next; //traverse the linked list
        i++;
    }
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
    Node *temp = head_;
    int i =0;
    while(i < index){
        temp = temp -> next; //traverse the linked list
        i++;
    }
    return temp;
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    if (index == 0){
        insert_front(value);
    }
    else if(index >= size_){ //if index greater than size, do nothing
        return false;
    }
    else if(index == size_ -1 ){
        insert_back(value);
    }
    else{
        // insert new node before the index
        Node *temp = new Node(value);
        Node *current = head_;
        int i =0;
        while( i < index){
            current = current -> next;
            i++;
        }
        current -> prev -> next = temp;
        current -> next -> prev = temp;
        temp -> prev = current -> prev;
        temp -> next = current;
        size_ ++;
        return true;
    }
}

bool DoublyLinkedList::insert_front(DataType value)
{
    Node *temp = new Node(value);
    if(size_ == 0){ // if no list, create new list
        head_ = temp;
        tail_ = head_;
        head_ -> prev = NULL;
        tail_ -> next = NULL;
        size_ ++;
        return true;
    }
    else{
        // add node in front of head_
        temp -> next = head_;
        head_ -> prev = temp;
        temp -> prev = NULL;
        head_ = temp;
        head_ -> prev = NULL;
        size_ ++;
        return true;
    }
    return false;
}

bool DoublyLinkedList::insert_back(DataType value)
{
    Node *temp = new Node(value);
    if(size_ == 0){
        head_ = temp;
        tail_ = head_;
        head_ -> prev = NULL;
        tail_ -> next = NULL;
        size_ ++;
        return true;
    }
    else{
        // add node behind tail_
        temp -> prev = tail_;
        tail_ -> next = temp;
        tail_ = temp;
        tail_ -> next = NULL;
        size_ ++;
        return true;
    }
    return false;
}

bool DoublyLinkedList::remove(unsigned int index)
{
    Node * current = head_;
    
    if(index > size_){
        return false;
    }
    
    for(int i= 0; i < index; i++){
        current = current -> next ;
    }
    current -> prev -> next = current -> next;
    current -> next -> prev = current -> prev;
    size_ --;
    return true;
    
}

bool DoublyLinkedList::remove_front()
{
    if(size_ > 0){
        Node * tempdelete = head_;
        head_ = head_ -> next;
        delete tempdelete;
        size_ --;
        return true;
    }
    return false;
}

bool DoublyLinkedList::remove_back()
{
    if(empty()){ //if list empty, do nothing
        return false;
    }
    else if(size_ > 0){ 
        Node * tempdelete = tail_; 
        tail_ = tail_ -> prev;
        delete tempdelete;
        size_ --;
        return true;
    }
    return false;
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    Node * current = head_;
    if(index >= size_){
        return false;
    }
    for(int i= 0; i < index; i++){
        current = current -> next;
    }
    current -> value = value; //replace value for the original value
    return true;
}
