//No errors discovered in building this program

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
    if (rear == nullptr)
        cout << "the queue is empty" << endl;
    
    else if (front == rear) {
        Node* temp = rear;
        front = nullptr;
        rear = nullptr;
        cout << "the data " << temp->data << " was deleted" << endl;
        delete temp;
    }
    
    else{
        Node* temp = rear;
        rear = rear -> prev;
        rear -> next = nullptr;
        cout << "the data " << temp->data << " was deleted" << endl;
        delete temp;
    }  
}

void display()
{
    if (front == nullptr) {
        cout << "the queue is empty!" << endl;
    }
    Node* temp = front;
    
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}



int main(int argc, const char * argv[])
{
    int data, loop=1;
    
    
    
    while (loop == 1) {
        
        
        cout << "\n============ MENU =========" << endl;
        cout << "1 - enqueue\n2 - dequeue\n3 - display linked list\n0 - exit program" << endl;
        cout << "Enter a choice: ";
        cin  >> loop;
        
       
            if (loop == 0) {
                exit(1);
            }
            else if (loop == 1){
                cout << "Enter a data: ";
                cin  >> data;
                
                enqueue(data);
            }
                
            
            else if (loop == 2){
                
                dequeue();
            }
            
            else if (loop == 3){
                display();
            }
            
            loop = 1;
        }
        
        
    
    
    return 0;
}


