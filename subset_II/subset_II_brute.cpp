class Solution {
    void fun(int ind,int n,set<vector<int>>& s, vector<int>&temp, vector<int>&nums){
        if(ind == n){
            s.insert(temp);
            return;
        }

        temp.push_back(nums[ind]);
        fun(ind+1, n, s, temp, nums);
        temp.pop_back();
        fun(ind+1, n, s, temp, nums);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        fun(0, n, s, temp, nums);
        vector<vector<int>> res(s.begin(), s.end());
        return res;
    }
};