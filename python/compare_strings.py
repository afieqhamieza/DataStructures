from ast import If
from operator import concat
from typing import List

def compare_strings(str1: List[str], str2: List[str]) -> List[int]:
    # WRITE YOUR BRILLIANT CODE HERE
    count = 0
    A = []  #array of final return

    for i in str2:
        min_str2 = min(i)
        for j in str1:
            min_str1 = min(j)

            min_comp = min(min_str1 + min_str2)

            if min_comp in i and min_comp in j:
                if i.count(min_comp) > j.count(min_comp):
                    count+=1
            elif min_comp in j:
                count+=1

        A.append(count)
        count=0

    return A

if __name__ == '__main__':
    str1 = "cccc nkala".split()
    str2 = "bbbbbe".split()
    res = compare_strings(str1, str2)
    print(' '.join(map(str, res)))