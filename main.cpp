//
//  main.cpp
//  Question5
//
//  Created by afieqha mieza azemi on 25/10/2019.
//  Copyright © 2019 afieqha mieza azemi. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* first = nullptr;

void pushNode(int data_in)
{
    Node* temp = new Node();
    temp -> data = data_in;
    temp -> next = first;
    first = temp;
}

void displayList()
{
    Node* temp = first;
    
    while (temp!=nullptr)
    {
        cout << "data: " << temp -> data << endl;
        temp = temp->next;
    }
}

int findSmallest(Node* first)
{
    int num=0;
    Node* temp = first;
    
    while (temp != nullptr) {
        if (temp == first || temp->data < num) {
            num = temp->data;
        }
        temp = temp->next;
    }
    
    return num;
}

int main(int argc, const char * argv[])
{
    pushNode(8);
    pushNode(3);
    pushNode(9);
    pushNode(2);
    
    cout << "displaying...\n" ;
    displayList();
    
    cout << "the smallest is " << findSmallest(first) << endl;
    
    return 0;
}
