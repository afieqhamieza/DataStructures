# Given an integer N, you are asked to divide N into a sum of a maximal number of positive even integers. All the numbers should also be different.

# For example, for N = 12, the following splits are valid: (2 + 10), (2 + 4 + 6) and (4 + 8). Among them, (2 + 4 + 6) contains the maximal number of integers. Note that N cannot be split into (2 + 2 + 4 + 4) as all the numbers should be different.

# Write a function:

# class Solution { public int[] solution(int N); }

# which, given a positive integer number N, returns an array containing the numbers from any maximal possible answer (any valid combination may be returned). If N cannot be divided in such a way, return an empty array.

# Result array should be returned as an array of integers.

# Examples:

# 1. Given N = 6, your function should return [2, 4] or [4, 2].

# 2. Given N = 7, your function should return [] (an empty array) as there is no valid split.

# 3. Given N = 22, your function should return [2, 4, 6, 10] in any order.

# 4. Given N = 4, your function should return [4].

# Write an efficient algorithm for the following assumptions:



from typing import List


def solution(N: int) -> List[int]:
    splits = []
    if N%2 != 0:
        return splits

    else:
        s=0
        i=2
        # while s<N:
        #     s+=i
        #     splits.append(i)
        #     i+=2

        count =0
        for i in range(0, N, 2):
            splits.append(i)


        if s == N:
            return splits
        else:
            splits.pop(splits.index(s-N))





    # if N <= 2:
    #     return []
        
    # splits = []

    # for i in range(2, N, 2):
    #     count = i

    #     split = []
    #     split.append(i)

    #     for j in range(2, N, 2):
    #         if count+j <= N and i != j:
    #             split.append(j)
    #             count += j
    #         elif count == N:
    #             if split not in splits:
    #                 splits.append(split)
    #         elif count+j > N:
    #             count -= (j-1)
    #             if (j-1) in split:
    #                 split.remove(j-1)
    #             continue

    # if not splits:
    #     return []

    # while len(splits) != 1:
    #     if len(splits[0]) >= len(splits[1]):
    #         splits.remove(splits[1])

    # return splits[0]

if __name__ == '__main__':
    print(solution(6))