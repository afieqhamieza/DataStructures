//
//  main.cpp
//  Question4
//
//  Created by afieqha mieza azemi on 06/11/2019.
//  Copyright © 2019 afieqha mieza azemi. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

void heaping(int arr[], int size, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < size && arr[left] < arr[smallest]) // left>size &&
        smallest = left;
    
    if (right < size && arr[right] < arr[smallest])
        smallest = right;
    
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        
        heaping(arr, size, smallest);
    }
}

void buildHeap (int arr[], int size)
{
    int index = (size/2) - 1;
    
    for (int i = index; i >= 0; i--)
        heaping(arr, size, i); //arr i size
    
}

void deleteRoot(int arr[], int& size)
{
    int lastElement = arr[size - 1];
    
    arr[0] = lastElement;
    
    size = size - 1;
    
    heaping(arr, size, 0);
}

void printHeap(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main(int argc, const char * argv[])
{
    //-------write from file-------//
    ofstream outfile("/Users/afieqhamiezaazemi/Documents/Fall 2019/Data Structures/Assignment 3/minHeap.txt");
    if (outfile.is_open())
    {
        for (int i=0; i<100; i++)
        {
            int x = 50 + rand() % 501 ;
            
            outfile << x;
            outfile << " ";
        }
    }
    else
        cout << "Unable to open file";
    
    outfile.close();
    
    // ------read from file------//
    int arr[100];
    ifstream infile("/Users/afieqhamiezaazemi/Documents/Fall 2019/Data Structures/Assignment 3/minHeap.txt");
    if (infile.is_open())
    {
        for (int i=0; i<100; i++) {
            infile >> arr[i];
        }
    }
    
    else
        cout << "Unable to open file";
    
    infile.close();
    
    int size = sizeof(arr) / sizeof(arr[0]);
    
    buildHeap(arr, size);
    printHeap(arr, size);
    
    cout << "\ndeleting 10 elements..." << endl;
    for (int i=0; i<10; i++) {
        deleteRoot(arr, size);
    }
    
    printHeap(arr, size);
    
    return 0;
}
