# You are given a scratchcard consists of a row of non-negative integers. 
# To win the scratch game, you need to scratch at least 2 numbers of the same value. 
# You can only scratch consecutive numbers from the card. Scratching each number costs 1 dollar. 
# Return the minimum cost to win the game, or -1 if winning is not possible.


from typing import List

def min_cost_to_win(nums: List[int]) -> int:
    possibleScratches = []

    for i in range(0, len(nums)):
        for j in range(i+1, len(nums)):
            if nums[i] == nums[j]:
                possibleScratches.append(nums[i:j+1])
            elif j == len(nums)-1:
                break

    print("possibleScratches: ", possibleScratches)

    while len(possibleScratches) > 1:
        if len(possibleScratches[0]) >= len(possibleScratches[1]):
            possibleScratches.remove(possibleScratches[0])
        elif len(possibleScratches[0]) < len(possibleScratches[1]):
            possibleScratches.remove(possibleScratches[1])
        
    return (len(possibleScratches[0]) if len(possibleScratches) !=0 else -1)

if __name__ == '__main__':
    nums = [1, 3, 4, 2, 3, 4, 5]
    res = min_cost_to_win(nums)
    print(res)
