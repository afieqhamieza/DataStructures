# Imagine you have a special keyboard with all keys in a single row. 
# The layout of characters on a keyboard is denoted by a string keyboard of length 26. 
# Initially your finger is at index 0. To type a character, you have to move your finger 
# to the index of the desired character. The time taken to move your finger from index i to index j is abs(j - i).

# Given a string keyboard that describe the keyboard layout and a string text, 
# return an integer denoting the time taken to type string text.

from typing import List


def type_time(str: List[str], text: List[str]) -> int:

    current_i = 0
    timeTaken = 0

    for i in range(0, len(text)):
        text_i = str.index(text[i])

        time = abs(text_i - current_i)
        timeTaken += time
        print(text)
        current_i = str.index(text[i])

    return timeTaken

if __name__ == '__main__':
    str = "abcdefghijklmnopqrstuvwxy"
    text = "cba"
    print(type_time(list(str), list(text)))