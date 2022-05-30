# You are given an integer array nums. In one move, you can choose one element of nums and change it by any value.
# Return the minimum difference between the largest and smallest value of nums after performing at most three moves.


class Solution(object):
    def minDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        nums.sort()
        
        smallest = nums[0]
        
        if len(nums) <= 3:
            return 0

        ans = nums[len(nums)-1] - nums[0]
        
        i=0
        for j in range(len(nums)-4, len(nums)):
            ans = min(ans, nums[j] - nums[i])
            i+=1
        
        
        return ans
            
        