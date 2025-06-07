class Solution:
    def myAtoi(self, s: str) -> int:
        i=0
        n=len(s)
        inf = 2**31-1
        ninf = -2**31

        while i<n and s[i] == ' ':
            i+=1
        
        if i==n:
            return 0
        
        sign  = 1
        if s[i] == '-' or s[i]=='+':
            if s[i] == '-':
                sign = -1
            i+=1
        
        res = 0

        while i<n and s[i].isdigit():
            dig = int(s[i])
            res = res*10 + dig
            if sign == 1 and res > inf:
                return inf
            if sign == -1 and -res < ninf:
                return ninf
            i+=1
        
        return res*sign