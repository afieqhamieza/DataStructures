
# Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
# and return an array of the non-overlapping intervals that cover all the intervals in the input.



from math import sqrt
from typing import List

def closestDelivery(allLocations: List[List[int]], numDeliveries: int) -> List:
    distances = []

    for x, y in allLocations:
        dist = sqrt((x*x)+(y*y))
        distances.append(dist)

    mapLocDist = list(zip(allLocations, distances))
    mapLocDist = sorted(mapLocDist, key=lambda x: x[1])

    deliveries = []

    for i in range(numDeliveries):
        deliveries.append(mapLocDist[i][0])
        
    return deliveries


if __name__ == '__main__':
    allLocations = [ [1,2], [3,4], [1,-1]]
    numDeliveries = 2

    print(closestDelivery(allLocations, numDeliveries))