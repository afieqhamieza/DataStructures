#include <iostream>
using namespace std;

struct Stack
{
    char data;
    Stack* next;
};

Stack* top = nullptr;

void pushNode(char data_in)
{
    Stack* temp = new Stack();
    temp -> data = data_in;
    temp -> next = top;
    top = temp;
    
}

void popNode()
{
    if (top == nullptr) {
        cout << "the stack is empty" << endl;
    }
    
    else
    {
        Stack* temp = top;
        top = temp->next;
        delete temp;
    }
    
}

int priority(char x)
{
    if(x == '^')
        return 3;
    else if(x == '*' || x == '/')
        return 2;
    else if(x == '+' || x == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s)
{
    pushNode('N');
    int length = s.length();
    string output;
    
    for(int i = 0; i < length; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            output += s[i];
        
        else if(s[i] == '(')
            pushNode('(');
        
        else if(s[i] == ')')
        {
            while(top->data != 'N' && top->data != '(')
            {
                char c = top->data;
                popNode();
                output += c;
            }
            
            if(top->data == '(')
                popNode();
        }
        
        else
        {
            while(top->data != 'N' && priority(s[i]) <= priority(top->data))
            {
                char c = top->data;
                popNode();
                output += c;
            }
            
            pushNode(s[i]);
        }
    }

    while(top->data != 'N')
    {
        char c = top->data;
        popNode();
        output += c;
    }
    
    cout << output << endl;
}

int main (void)
{
    string s;
    cout << "Enter an equation (small letters only): ";
    cin >> s;

    infixToPostfix(s);
    
    return 0;
}
