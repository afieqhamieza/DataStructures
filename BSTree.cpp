

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    int level;
};

Node* root = nullptr;

void insert(int data_in)
{
    Node* temp = new Node();
    temp -> data = data_in;
    temp -> left = nullptr;
    temp -> right = nullptr;
    
    Node* ptr = new Node();
    Node* parent = new Node();
    
    if (root == nullptr)
        root = temp;
    
    else
    {
        ptr = root;
        while (ptr != nullptr)
        {
            parent = ptr;
            if (data_in < ptr->data)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        
        if (data_in < parent->data)
            parent -> left = temp;
        else
            parent -> right = temp;
        
    }
}

void preorder(Node *temp)
{
    if (temp != nullptr)
    {
        cout << temp -> data << " ";
        preorder(temp->left);
        preorder(temp -> right);
    }
}

Node* minValueNode(Node* temp)
{
    Node* current = temp;
    
    while (current && current->left != NULL)
        current = current->left;
    
    return current;
}

Node* remove(Node* root1, int x)
{
    if (root1 == NULL) 
        return root;
    
    if (x < root1->data)
        root1->left = remove(root1->left, x);
    else if (x > root1->data)
        root1->right = remove(root1->right, x);
    else
    {
        if (root1->left == NULL)
        {
            Node *temp = root1->right;
            free(root1);
            return temp;
        }
        else if (root1->right == NULL)
        {
            Node *temp = root1->left;
            free(root1);
            return temp;
        }
        
        Node* temp = minValueNode(root1->right);
        root1->data = temp->data;
        root1->right = remove(root1->right, temp->data);
    }
    
    return root1;
}

void inorder(Node *temp)
{
    if (temp != nullptr)
    {
        inorder(temp->left);
        cout << temp -> data << " ";
        inorder(temp -> right);
    }
}

void postorder(Node *temp)
{
    if (temp != nullptr)
    {
        postorder(temp->left);
        postorder(temp -> right);
        cout << temp -> data << " ";
    }
}

int main(int argc, const char * argv[])
{
    int num, choice=0;
    
    do {
        cout << "----------MENU----------" << endl
             << "1 - enter a number" << endl
             << "2 - delete a number" << endl
             << "3 - display" << endl
             << "4 - end program" << endl
             << "Enter a choice: ";
        cin  >> choice;
        
        switch (choice) {
            case 1:
                cout << "enter a number you want to insert: ";
                cin  >> num;
                insert(num);
                break;
                
            case 2:
                cout << "enter a number you want to remove: ";
                cin  >> num;
                root = remove(root, num);
                break;
                
            case 3:
                cout << "\n\npreoder traversing..." << endl;
                preorder(root);
                cout << "\ninoder traversing..." << endl;
                inorder(root);
                cout << "\npostoder traversing..." << endl;
                postorder(root);
                cout << "\n\n" ;
                break;
                
            default:
                break;
        }
    } while (choice != 4);
    
    
    
    
    
    return 0;
}
