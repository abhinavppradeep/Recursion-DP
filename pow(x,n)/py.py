class Solution:
    def myPow(self, x: float, n: int) -> float:
        N = abs(n)
        res = 1.0

        while N > 0:
            if N%2 == 1:
                res = res * x
                N-=1
            else:
                x=x*x
                N=N/2
        
        return res if n>=0 else 1/res