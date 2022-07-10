




from typing import List

def eraseOverlapIntervals(intervals: List[List[int]]) -> int:
    end, count = float('-inf'), 0

    print("intervals: ", intervals)

    for s, e in sorted(intervals, key=lambda x: x[1]):
        print("s: ", s, ", e: ", e)
        if s >= end: 
            end = e
        else: 
            count += 1

    return count


if __name__ == '__main__':
    intervals = [[1,2],[2,3],[3,4],[1,3]]
    print(eraseOverlapIntervals(intervals))