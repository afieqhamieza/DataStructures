# Given an array of positive integers representing the radii of circular pizzas and the number of guests at a movie party, 
# return the size of the largest piece of pizza (rounded to 4 decimal places) that can be cut so that every guest gets 
# a slice of pizza with the same size. It is not possible that a single slice has some part of one pizza and 
# some part of another pizza, and each guest gets only once slice of pizza.

import math
from typing import List

def get_max_pizza_slice_size(radii: List[int], guests: int) -> float:
    areas = [math.pi * r * r for r in radii]
    def isPossible(x):
        k = 0
        for a in areas:
            k += a // x
            if k >= guests:
                return True
        return False
     
    l, r = 0, max(areas)
    while l + 1e-5 <= r:
        x = (l + r) / 2
        if isPossible(x):
            l = x
        else:
            r = x

    return round(x, 4)

if __name__ == '__main__':
    radii = [int(x) for x in input().split()]
    guests = int(input())
    res = get_max_pizza_slice_size(radii, guests)
    print(f'{res:.4f}')
