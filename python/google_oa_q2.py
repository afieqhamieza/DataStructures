# You are given a string S consisting of N lowercase letters of the English alphabet. Find the length of the longest substring of S in which the number of occurrences of each letter is equal.

# For example, given S = "ababbcbc", substrings in which every letter occurs the same number of times are: "a", "b", "c", "ab", "ba", "bb", "bc", "cb", "abab" and "bcbc". The longest among them are "abab" and "bcbc" and their length equals 4.

# Write a function:

# int solution(string &S);

# that, given the string S of length N, returns the length of the longest substring in which the number of occurrences of each letter is equal.

# Examples:
# Given S = "ababbcbc", the function should return 4, as explained above.
# Given S = "aabcde", the function should return 5. The longest substring is "abcde", in which all letters occur once.
# Given S = "aaaa", the function should return 4. The longest substring is "aaaa", in which all letters occur four times.
# Given S = "daababbd", the function should return 6. The longest substring is "aababb", in which all letters occur three times.
# Assume that:
# N is an integer within the range [1..80];
# string S consists only of lowercase letters (a-z).
# In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment



from enum import unique
from itertools import combinations


def solution(s: str) -> int:

    ans = 0
    # substr = [s[x:y] for x, y in combinations(range(len(s) + 1), r = 2)] 
    substr = []
    for i in range(len(s)):
        for j in range(i+1, len(s)+1):
            substr.append(s[i:j])

    uniqueSubstr = []

    for i in range(0, len(substr)):
        uniqueChars = dict.fromkeys(substr[i], 0)
        for j in substr[i]:
            uniqueChars[j] += 1

        first = list(uniqueChars.values())[0]

        sameUnique = True
        
        for c in uniqueChars:
            if uniqueChars[c] != first:
                sameUnique = False
                break

        if sameUnique and (substr[i] not in uniqueSubstr):
            uniqueSubstr.append(substr[i])
            
    for i in uniqueSubstr:
        ans = max(ans, len(i))

    return ans
    
if __name__ == '__main__':
    print(solution("ababbcbc"))