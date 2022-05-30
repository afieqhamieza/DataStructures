# Given a string s with length n, how many ways can you split it into two substrings s_1 and s_2 
# such that the number of unique characters in s_1 and s_2 are the same?

# Parameter
# s: A string with length n.
# Result
# The number of ways you can split it into two substrings that satisfy the condition.



import collections


def total_ways_to_split_strings(s: str) -> int:
    # WRITE YOUR BRILLIANT CODE HERE
    left_count = collections.Counter()
    right_count = collections.Counter(s)
    
    res = 0
    
    for c in s:
        left_count[c] += 1
        right_count[c] -= 1
        
        if right_count[c] == 0:
            del right_count[c]
        
        if len(left_count) == len(right_count):
            res += 1
            
    return res

if __name__ == '__main__':
    # "aaa" = 2
    # "bac" = 0
    # "sampletext" = 1
    # "uwuwuwu" = 4
    # "goooooooogle" = 1
    # "SirSussusAmugus" = 4
    # "SheSellSeaShellOnASeaShore" = 1
    # "1234223432344234" = 1
    
    s = input()
    res = total_ways_to_split_strings(s)
    print(res)
