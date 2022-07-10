
# Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
# and return an array of the non-overlapping intervals that cover all the intervals in the input.



from typing import List

def mergeOverlapIntervals(intervals: List[List[int]]) -> List:
    out = []

    for i in sorted(intervals, key=lambda i: i[0]):
        if out and i[0] <= out[-1][1]:
            out[-1][1] = max(out[-1][1], i[1])
        else:
            out += [i]

    return out


if __name__ == '__main__':
    intervals = [[7,9],[3,4]]
    print(mergeOverlapIntervals(intervals))