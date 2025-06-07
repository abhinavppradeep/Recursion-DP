class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        def backtr(ind :int, temp: List[int]):
            res.append(temp[:])
            
            for i in range(ind, len(nums)):
                if i>ind and nums[i] == nums[i-1]:
                    continue
                temp.append(nums[i])
                backtr(i+1, temp)
                temp.pop()


        nums.sort()
        res = []
        backtr(0, [])

        return res