class Solution {
    void fun(int ind,int n,vector<vector<int>>& res, vector<int>&temp, vector<int>&nums){
        res.push_back(temp);

        for(int i=ind;i<n;i++){
            if(i>ind && nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);
            fun(i+1, n, res, temp, nums);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        fun(0, n, res, temp, nums);
        return res;
    }
};