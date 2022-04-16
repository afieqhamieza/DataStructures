# You have a number written down on a piece of paper. Unfortunately, you are extremely clumsy 
# and you knocked over a bottle of ink, which covered the paper. This causes some numbers to be completely illegible.

# This number is very important to you, so you want to reconstruct the number. You don't remember the original number, 
# but you distinctly remember that this number has two peculiar attributes: it has no zeros anywhere in the number, 
# and each adjacent digits are distinct. With this information, it is not necessarily possible to guarantee a number, 
# so you just want to find the lowest possible number given the current information.

# Parameter
# digits: A string of length n consisting of 1 ~ 9 and/or ? (which represents an illegible digit).
# Result
# A string representing the lowest possible number that satisfy the conditions described above.


def min_possible_int(digits: str) -> str:
    # WRITE YOUR BRILLIANT CODE HERE
    digitList = list(digits)

    # iterate over str as array
    for i in range(0, len(digitList)):
        # list of 1-9
        possibleVal = list(range(1, 9))
        leftN, rightN = '',''
        # upon encounter '?', 
        if digitList[i] == '?':
            # take note of neighbors, 
            # if neighbors is a number, remove neighbors number from list 1-9

            if i > 0:
                leftN = digitList[i-1]
                if leftN != '?':
                    possibleVal.remove(int(leftN)) if int(leftN) in possibleVal else None 
            if i < len(digitList)-1:
                rightN = digitList[i+1]
                if rightN != '?':
                    possibleVal.remove(int(rightN)) if int(rightN) in possibleVal else None 

            # replace '?' with min(1-9)
            digitList[i] = str(min(possibleVal))

    return ''.join(digitList)

if __name__ == '__main__':
    digits = "?1???2??3???4?"
    res = min_possible_int(digits)
    print(res)
