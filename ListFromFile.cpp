//
//  main.cpp
//  Question2
//
//  Created by afieqha mieza azemi on 05/11/2019.
//  Copyright © 2019 afieqha mieza azemi. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    string name;
    string tel;
    Node* next;
};

Node* first;

void pushNode(string name_in, string tel_in)
{
    Node* temp = new Node();
    temp -> name = name_in;
    temp -> tel = tel_in;
    temp -> next = first;
    first = temp;
}

void popNode(string removeContact)
{
    Node* temp = first;
    
    while (temp->name != removeContact && temp != nullptr) {
        temp = temp->next;
    }
    
    if (temp->name == removeContact) {
        Node* p = first;
        while (p->next != temp) {
            p = p->next;
        }
        
        if (p == first) {
            first->next = temp->next;
        }
        else
            p->next = temp->next;
        
        cout << temp->name << "(" << temp->tel << ") will be deleted" << endl;
        delete temp;
    }
    
}

void displayList()
{
    Node* temp = first;
    
    while (temp!=nullptr)
    {
        cout << "name: " << temp -> name << "\t\ttelephone number: " << temp -> tel << endl;
        temp = temp->next;
    }
}

int menu()
{
    int choice;
    
    cout << "\n\nchoose one of the following: " << endl;
    cout << "1 - insert new data" << endl
         << "2 - remove a data" << endl
         << "3 - print the list" << endl
         << "4 - exit program" << endl;
    cin  >> choice;
    
    return choice;
}

int main(int argc, const char * argv[])
{
    ifstream infile;
    ofstream outfile;
    string name_in, removeContact, tel_in;
    
    infile.open("/Users/afieqhamiezaazemi/Documents/Fall 2019/Data Structures/Assignment 3/telephoneNumbers.txt");
    
    if (!infile)
    {
        cout << "fail to open file" << endl;
        exit(1);
    }
    
    for (int i=0; i<4; i++)
    {
        infile >> name_in;
        infile >> tel_in;
        
        pushNode(name_in, tel_in);
    }
    
    infile.close();
    
    while (1) {
        switch (menu()) {
            case 1:
                cout << "Enter the name: ";
                cin  >> name_in;
                cout << "Enter the telephone number: ";
                cin  >> tel_in;
                
                pushNode(name_in, tel_in);
                break;
                
            case 2:
                cout << "Enter the name of the contacts that you want to delete: ";
                cin  >> removeContact;
                popNode(removeContact);
                break;
                
            case 3:
                displayList();
                break;
                
            case 4:
                exit(1);
                
            default:
                break;
        }
    }
    
    
    
    
    return 0;
}
