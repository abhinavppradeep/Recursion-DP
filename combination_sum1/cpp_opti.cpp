class Solution {
    void backtr(vector<int>& candidates, int rem, int start, vector<int>& temp,
                vector<vector<int>>& res) {
        if (rem == 0) {
            res.push_back(temp);
            return;
        }

        if (rem < 0)
            return;

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > rem) break;
            temp.push_back(candidates[i]);
            backtr(candidates, rem - candidates[i], i, temp, res);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());

        backtr(candidates, target, 0, temp, res);

        return res;
    }
};