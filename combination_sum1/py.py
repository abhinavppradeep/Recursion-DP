class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def backtr(rem , start, temp):
            if rem == 0:
                res.append(temp[:])
                return
            if rem < 0:
                return
            
            for i in range(start, len(candidates)):
                if rem < candidates[i]:
                    break
                temp.append(candidates[i])
                backtr(rem-candidates[i], i, temp)
                temp.pop()


        candidates.sort()
        res = []
        backtr(target, 0, [])
        return res