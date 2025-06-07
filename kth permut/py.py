class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        nums = [str(i) for i in range(1, n+1)]
        fact = [1] * n
        for i in range(1, n):
            fact[i]=fact[i-1]*i
        
        res = []
        k=k-1

        for i in range(n, 0, -1):
            ind = k // fact[i-1]
            res.append(nums[ind])
            nums.pop(ind)
            k=k%fact[i-1]
        
        return "".join(res)
