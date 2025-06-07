class Solution {
    void backtr(vector<int>& candidates, int rem, int start,
                vector<vector<int>>& res, vector<int>& temp) {
        if (rem == 0) {
            res.push_back(temp);
            return;
        }
        if (rem < 0)
            return;

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > rem)
                break;
            temp.push_back(candidates[i]);
            backtr(candidates, rem - candidates[i], i + 1, res, temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        backtr(candidates, target, 0, res, temp);
        return res;
    }
};