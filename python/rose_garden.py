# You are planting onions to make salads. Given an array of positive integers that indicates 
# the day that each of your onion is ready for harvest, the minimum number of adjacent mature onions required for a salad, 
# and the number of salads you want to make, return the earliest day that you can finish making all salads. 
# If it is impossible to make the required number of salads, return -1.

# Input
# onions: an array of positive integers. Onion i will be ready for harvest on day onions[i].
# k: the minimum number of adjacent onions required to make a salad.
# n: the number of salads you want to make.
# Output
# Return the earliest day that you can finish making n salads, or -1 if the task is impossible.

from typing import List

def min_days_salads(onions: List[int], k: int, n: int) -> int:
    # WRITE YOUR BRILLIANT CODE HERE    
    dayCount = 0
    onionCount = 0
    maxDay = max(onions)

    while onionCount<n: 
        if dayCount > maxDay:
            return -1

        dayCount+=1
        onions = [x-1 for x in onions]
        
        for i in range(0, len(onions)-1):
            adj = 1

            for j in range(i+1, len(onions)):
                if onions[i] <= 0 and onions[j] <= 0:
                    adj+=1

                    if adj >= k:
                        onionCount+=1

                        if j == len(onions):
                            del onions[i:]
                            i=0
                        else:
                            del onions[i:j+1]
                            i=0
                        break
                else:
                    break

    return dayCount

if __name__ == '__main__':
    onions = [3000,3000,3000,3000]
    k = 1
    n = 1
    res = min_days_salads(onions, k, n)
    print(res)
