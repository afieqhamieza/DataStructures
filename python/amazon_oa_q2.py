
# Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
# and return an array of the non-overlapping intervals that cover all the intervals in the input.



from math import sqrt
from operator import itemgetter
from typing import List

def routePairs(maxTravelDist, forwardRouteList, returnRouteList):
    # Write your code here
    pairRouteList = []
    maxTravelDistList = []
    
    for indexF, distF in forwardRouteList:
        # print("index: ", indexF, ", dist: ", distF)

        tempRouteList = []
        tempMaxDist = []

        for indexR, distR in returnRouteList:
            pair = [indexF, indexR]
            dist = distF + distR

            if dist > maxTravelDist:
                continue

            tempRouteList.append(pair)
            tempMaxDist.append(dist)

        if tempRouteList:
            mapRouteDist = list(zip(tempRouteList, tempMaxDist))
            maxDist_i = max(mapRouteDist, key=itemgetter(1))[1]

            # print(maxDist_i)

            for r, d in mapRouteDist:
                # print("r: ", r, ", d: ", d)
                if d == maxDist_i:
                    pairRouteList.append(r)
                    maxTravelDistList.append(maxDist_i)

   

    pairRouteListFinal = []
    
    if pairRouteList:
    
        mapRouteDist2 = list(zip(pairRouteList, maxTravelDistList))
        maxDist_i2 = max(mapRouteDist2, key=itemgetter(1))[1]

        # print(maxDist_i)

        for r, d in mapRouteDist2:
            # print("r: ", r, ", d: ", d)
            if d == maxDist_i2:
                pairRouteListFinal.append(r)




    return pairRouteListFinal


if __name__ == '__main__':
    print(routePairs(10000, [[1,3000], [2, 5000], [3, 7000], [4, 10000]], [[1, 2000], [2, 3000], [3, 4000], [4, 5000]]))