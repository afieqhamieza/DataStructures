#A string is defined to be "strictly smaller" than another string when the number of occurrences of the lexicographically smallest 
# character in the string is less than that of the other. For example, "abcd" is strictly smaller than "aaa" because 
# the smallest character in "abcd", "a", appears 1 time, whereas the smallest character in "aaa", "a", appears 3 times.

#In another example, "d" is strictly smaller than "ff" because the smallest character in "d", 'd', appears 1 time, 
# and the smallest character in "ff", 'f', appears 2 times.

#Given a list of strings str1 with m elements, and another list of strings str2 with n elements, return an array A of n integers. 
# For 0 <= i < n, A[i] is the number of strings in str1 that are strictly smaller than the comparison i-th string in str2. 
# Focus on correctness instead of performance in your solution.




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