class Solution {
    int fibi(int ind, vector<int>& dp) {
        if (ind <= 1)
            return ind;
        if (dp[ind] != -1)
            return dp[ind];
        else {
            return dp[ind] = fibi(ind - 1, dp) + fibi(ind - 2, dp);
        }
    }

public:
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return fibi(n, dp);
    }
};