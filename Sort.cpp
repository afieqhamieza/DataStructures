//
//  main.cpp
//  finalCode
//
//  Created by afieqha mieza azemi on 27/11/2019.
//  Copyright © 2019 afieqha mieza azemi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void writeToFile(string pathname, int arr[], int size);
void readFromFile(string pathname, int arr[], int size);
void bubble(int arr[], int size, int& count);
void selection(int arr[], int size, int& count);
void heap(int arr[], int n, int& count);
void heapup(int arr[], int size, int i);
void display(int arr[], int size);

int main(int argc, const char * argv[])
{
    int size = 50000;
    int ori[size], bubbleArr[size], selectArr[size], heapArr[size];
    int bubbleCount, selectCount, heapCount;
    
    for (int i=0; i<size; i++)
        ori[i] = rand() % 1001;
    
    writeToFile("/Users/afieqhamiezaazemi/Documents/Fall 2019/Data Structures/Assignment 4/data.txt", ori, size);
    
    readFromFile("/Users/afieqhamiezaazemi/Documents/Fall 2019/Data Structures/Assignment 4/data.txt", bubbleArr, size);
    bubble(bubbleArr, size, bubbleCount);
    writeToFile("/Users/afieqhamiezaazemi/Documents/Fall 2019/Data Structures/Assignment 4/bubble.txt", bubbleArr, size);
    
    readFromFile("/Users/afieqhamiezaazemi/Documents/Fall 2019/Data Structures/Assignment 4/data.txt", selectArr, size);
    selection(selectArr, size, selectCount);
    writeToFile("/Users/afieqhamiezaazemi/Documents/Fall 2019/Data Structures/Assignment 4/selection.txt", selectArr, size);
    
    readFromFile("/Users/afieqhamiezaazemi/Documents/Fall 2019/Data Structures/Assignment 4/data.txt", heapArr, size);
    heap(heapArr, size, heapCount);
    writeToFile("/Users/afieqhamiezaazemi/Documents/Fall 2019/Data Structures/Assignment 4/heap.txt", heapArr, size);
    
    ofstream outfile;
    
    outfile.open("/Users/afieqhamiezaazemi/Documents/Fall 2019/Data Structures/Assignment 4/comparison.txt");
    
    if (outfile.is_open())
    {
        outfile << "bubble" << "\t\tselection" << "\theap" << endl;
        outfile << bubbleCount << "\t" << selectCount << "\t" << heapCount << endl;
        
        outfile.close();
    }
    
    return 0;
}

void writeToFile(string pathname, int arr[], int size)
{
    ofstream outfile;
    
    outfile.open(pathname);
    
    if (outfile.is_open())
    {
        for (int i=0; i<size; i++)
            outfile << arr[i] << endl;
        
        outfile.close();
    }
}

void readFromFile(string pathname, int arr[], int size)
{
    ifstream infile;
    
    infile.open(pathname);
    
    if (infile.is_open())
    {
        for (int i=0; i<size; i++)
            infile >> arr[i];
        
        infile.close();
    }
}

void bubble(int arr[], int size, int& count)
{
    for (int i=0; i<size-1; i++)
    {
        count++;
        for (int j=0; j<size-i-1; j++)
        {
            count++;
            
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

void selection(int arr[], int size, int& count)
{
    for (int i=0; i<size-1; i++)
    {
        count++;
        int min_idx = i;
        
        for (int j=i+1; j<size; j++)
        {
            count++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        
        swap(arr[min_idx], arr[i]);
    }
}

void heap(int arr[], int size, int& count)
{
    for (int i=size/2-1; i>=0; i--)
    {
        count++;
        heapup(arr, size, i);
    }
    
    for (int i=size-1; i>=0; i--)
    {
        count++;
        swap(arr[0], arr[i]);
        
        heapup(arr, i, 0);
    }
}

void heapup(int arr[], int size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left<size && arr[left]>arr[largest])
        largest = left;
    
    if (right<size && arr[right]>arr[largest])
        largest = right;
    
    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        
        heapup(arr, size, largest);
    }
}

void display(int arr[], int size)
{
    for (int i=0; i<size; i++)
        cout << arr[i] << " ";
    
    cout << endl;
}

