//
//  main.cpp
//  Question2
//
//  Created by afieqha mieza azemi on 27/09/2019.
//  Copyright © 2019 afieqha mieza azemi. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(int data_in)
{
    Node* temp = new Node();
    temp -> data = data_in;
    temp -> next = nullptr;
    temp -> prev = nullptr;
    
    if (front == nullptr)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        temp -> next = front;
        front -> prev = temp;
        front = temp;
    }
}

void dequeue()
{
    Node* temp = rear;
    rear = rear -> prev;
    rear -> next = nullptr;
    delete temp;
}

int sum()
{
    int sum = 0;
    Node* temp = front;
    
    while (temp != nullptr) {
        sum += temp -> data;
        temp = temp->next;
    }
    
    return sum;
}

float average()
{
    Node* temp = front;
    int count = 0;
    
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    float average = sum() / count;
    
    return average;
}

int main(int argc, const char * argv[])
{
    int num[5] = {2,2,2,2,2};
    
    for (int i=0; i<5; i++) {
        enqueue(num[i]);
    }
    
    cout << "the sum is " << sum() << " and the average is " << average() << endl;
    
    return 0;
}


