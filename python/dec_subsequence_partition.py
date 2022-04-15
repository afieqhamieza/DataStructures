# Given an integer array, split it into strictly decreasing subarrays. 
# Return the minimum number of decreasing subarrays you can get from splitting the array.

from typing import List

def min_decreasing_partitions(arr: List[int]) -> int:
    count = 0

    if len(arr) == 0:
        return count
    
    while len(arr)>0:
        tempArr = []
        x = 0
        tempArr.append(arr[0])

        if len(arr) == 1:
            count +=1

        for j in range (1, len(arr)):
            if j == len(arr)-1 and arr[x] > arr[j]:
                tempArr.append(arr[j])
                count+=1
            elif j == len(arr)-1:
                count+=1
            elif arr[x] > arr[j]:
                x=j
                tempArr.append(arr[j])

        for i in tempArr:
            arr.remove(i)
            
    return count

if __name__ == '__main__':
    arr = [19, 8, 5]
    res = min_decreasing_partitions(arr)
    print(res)
