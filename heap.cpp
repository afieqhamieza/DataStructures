//
//  main.cpp
//  reheap up and reheap down
//
//  Created by afieqha mieza azemi on 06/11/2019.
//  Copyright © 2019 afieqha mieza azemi. All rights reserved.
//

#include <iostream>
using namespace std;

void heaping(int arr[], int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < size && arr[left] > arr[largest])
        largest = left;
    
    if (right < size && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) 
    {
        swap(arr[i], arr[largest]);
        heaping(arr, size, largest);
    }
}

void buildHeap (int arr[], int size)
{
    int index = (size/2) - 1;
    
    for (int i = index; i >= 0; i--)
        heaping(arr, size, i);
    
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
    int arr[50];
    
    for (int i=0; i<50; i++) 
        arr[i] = 1 + rand() % 51;
    
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printHeap(arr, size);
    buildHeap(arr, size);
    printHeap(arr, size);
    
    for (int i=0; i<50 ; i++) 
    {
        deleteRoot(arr, size);
        printHeap(arr, size);
    }
    
    return 0;
}
