# An array A is greater than an array B if the first non-matching item in both arrays has a greater value in A than in B. 
# For example,
    # A = [3, 4, 9, 6, 8]
    # B = [3, 4, 8, 6, 7]
# A is bigger than B because the first non-matching element is larger in A (A[2] > B[2]).

# A contiguous subarray is a subarray that has consecutive indexes.

# Given an array arr consisting of n integers and an integer k, return the largest contiguous subarray of length k 
# from all the possible contiguous subarrays of length k.


from typing import List

def get_largest_subarray(arr: List[int], k: int) -> List[int]:
    # WRITE YOUR BRILLIANT CODE HERE
    contiguousSubarray = []
    largerSubarray = []

    # list out all contiguous subarray
    for j in range(1, len(arr) + 1):
        for i in range(len(arr) - j+1):
            if len(arr[i:i+j]) == k:
                contiguousSubarray.append(arr[i:i+j])

    # find larger subarray
    for i in contiguousSubarray:
        flag = 0
        for k in range(0, len(i)):
            if i[k] > arr[k] and flag == 0:
                flag = 1
                largerSubarray.append(i)
                
            elif i[k] < arr[k]:
                flag = 1

            elif k == len(i)-1 and flag == 0:
                flag = 1
                largerSubarray.append(i)

    while len(largerSubarray) > 1:
        largestSubarray = []
        for i in range(0, len(largerSubarray)-1):
            largestSubarray.append(findLargest(largerSubarray[i], largerSubarray[i+1]))

        largerSubarray = largestSubarray

    
    return largerSubarray

def findLargest(arrA: List[int], arrB: List[int]) -> List[int]:
    for i in range(0, len(arrA)-1):
        if arrA[i] > arrB[i]:
            return arrA
            
        elif arrB[i] > arrA[i]:
            return arrB

    return arrB



if __name__ == '__main__':
    arr = [500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 500, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499, 500, 499]
    k = 10
    res = get_largest_subarray(arr, k)
    print(' '.join(map(str, res)))
