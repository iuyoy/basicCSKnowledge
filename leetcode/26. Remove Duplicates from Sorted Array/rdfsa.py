class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 0: return 0
        i = 0
        for n in nums:
            if n != nums[i]:
                i+=1
                nums[i] = n
        return i+1