# You work in a restaurant and is tasked to fill some bowls with soup in a big stock pot. 
# The bowls are positioned in a row, and you are going to fill the bowls with a large ladle. 
# To avoid mistakes, you have decided to:

# Fill the bowls from left to right;
# Fill each bowl if you have enough soup for it, otherwise refill the ladle with more soup;
# Fill each bowl in one go without taking a break to refill the ladle. This means that you may sometimes 
# have to refill your ladle before or after filling a bowl, even though the ladle isn't completely empty.
# You start at the stock pot, which is positioned one step before the first bowl. 
# How many steps will you take to finish filling all the bowls in the row? 
# The bowls are positioned one step apart from each other.

# Given an array of n integers representing the amount of soup required for each bowl and the ladle capacity, 
# return the number of steps needed to fill all the bowls.

from itertools import count
from typing import List

def min_steps(bowls: List[int], capacity: int) -> int:
    # WRITE YOUR BRILLIANT CODE HERE

    stepCount = 0

    # while all bowl is not full
    while any(x!=0 for x in bowls):
        # ladle = capacity
        ladleCap = capacity
        # loop bowls and fill
        for i in range (0, len(bowls)):
            # if ladle capacity fits the bowl's capacity and bowl capacity is not 0, 
                # deecrease each bowl to 0 when filled,
                # decrease ladle capacity by bowl capacity
                # increase count by 1
            if bowls[i] <= ladleCap and bowls[i]!=0:
                ladleCap -= bowls[i]
                bowls[i] -= bowls[i]
                stepCount += 1
            # if ladle capacity fits the bowl's capacity and bowl capacity is 0,
                # increase count by 1
            elif bowls[i] <= ladleCap and bowls[i] == 0:
                stepCount += 1
            # else
                # increase count by steps back
                # break
            else:
                stepCount += i
                break

    return stepCount

if __name__ == '__main__':
    bowls = [2, 4, 5, 1, 2]
    capacity = 6
    res = min_steps(bowls, capacity)
    print(res)
