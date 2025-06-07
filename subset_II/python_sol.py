class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        def backtr(index :int, temp: List[int]):
            if index == len(nums):
                res_set.add(tuple(temp))
                return
            
            temp.append(nums[index])
            backtr(index+1, temp)
            temp.pop()
            backtr(index+1, temp)


        nums.sort()
        res_set = set()
        backtr(0, [])

        return [list(t) for t in res_set]