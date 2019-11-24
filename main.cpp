//
//  main.cpp
//  Question1
//
//  Created by afieqha mieza azemi on 29/09/2019.
//  Copyright © 2019 afieqha mieza azemi. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char data;
    Node* next;
};

Node* first = nullptr;

void pushNode(char data_in)
{
    Node* temp = new Node();
    temp->data = data_in;
    temp->next = nullptr;
    
    if (first == nullptr)
        first = temp;
    
    else
    {
        temp->next = first;
        first = temp;
    }
}

void popNode()
{
    Node* temp = first;
    first = temp->next;
    delete temp;
}

bool checkParanthesis(string exp)
{
    int n = exp.length();
    
    for (int i=0; i<n; i++)
    {
        if (exp[i] == '(')
        {
            pushNode(exp[i]);
        }
        else if (exp[i] == ')' )
        {
            if (first == nullptr)
            {
                return false;
            }
            
            else
            {
                popNode();
            }
        }
    }
    
    if (first != nullptr)
    {
        return false;
    }
    
    return true;
}

int main(int argc, const char * argv[])
{
    string exp = "((9+9))";
    
    if (!checkParanthesis(exp)) {
        cout << "paranthesis does not match!" << endl;
    }
    else
        cout << "paranthesis match!" << endl;
    
    return 0;
}
