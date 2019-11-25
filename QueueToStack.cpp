//
//  main.cpp
//  Queue to stack
//
//  Created by afieqha mieza azemi on 25/10/2019.
//  Copyright © 2019 afieqha mieza azemi. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node* front = nullptr;
Node* rear = nullptr;
Node* top = nullptr;

void enqueue(int data_in)
{
    Node* temp = new Node();
    temp -> data = data_in;
    temp -> next = nullptr;
    
    if (front == nullptr)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear -> next = temp;
        rear = temp;
    }
}

int dequeue()
{
    int num=0;
    if (front == nullptr)
        cout << "the queue is empty" << endl;
    
    else if (front == rear) {
        Node* temp = front;
        front = nullptr;
        rear = nullptr;
        //cout << "the data " << temp->data << " was deleted" << endl;
        num = temp -> data;
        delete temp;
    }
    
    else{
        Node* temp = front;
        front = front -> next;
        //cout << "the data " << temp->data << " was deleted" << endl;
        num = temp -> data;
        delete temp;
    }
    
    return num;
}

void displayQ()
{
    if (front == nullptr) {
        cout << "the queue is empty!" << endl;
        return;
    }
    Node* temp = front;
    
    cout << " | ";
    while (temp != nullptr) {
        cout << temp->data << " | ";
        temp = temp->next;
    }
}

void pushNode(int data_in)
{
    Node* temp = new Node();
    temp -> data = data_in;
    temp -> next = top;
    top = temp;
    
}

int popNode()
{
    int num=0;
    if (top == nullptr) {
        cout << "the stack is empty" << endl;
    }
    
    else
    {
        Node* temp = top;
        top = temp->next;
        num = temp -> data;
        delete temp;
    }
    
    return num;
}

void displayStack()
{
    if (top == nullptr) {
        cout << "the stack is empty!" << endl;
        return;
    }
    Node* temp = top;
    
    cout << " | ";
    while (temp != nullptr) {
        cout << temp->data << " | ";
        temp = temp->next;
    }
}

void queueToStack()
{
    
    for (int i=3; i<7; i++) {
        int num = dequeue();
        pushNode(num);
        enqueue(num);
    }
    
    for (int i=3; i<7; i++) {
        enqueue(popNode());
    }
    
    for (int i=3; i<7; i++) {
        int num = dequeue();
        pushNode(num);
        enqueue(num);
    }
    
    for (int i=3; i<7; i++){
        popNode();
    }
    
    for (int i=3; i<7; i++) {
        pushNode(dequeue());
    }
    
}

int main()
{
    for (int i=3; i<7; i++) {
        enqueue(i);
    }
    
    cout << "real queue...\t" ;
    displayQ();
    
    cout << "\n------------------------------------\n";
    
    
    queueToStack();
    cout << endl;
    cout << "\nqueue now...\t" ;
    displayQ();
    cout << "\nstack now...\t" ;
    displayStack();
    cout << endl<< endl;
    
}
