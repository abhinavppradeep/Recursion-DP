class Solution {
    void recur(int ind, vector<vector<int>>&ans, vector<int> &nums){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=ind;i<nums.size();i++){
            swap(nums[ind], nums[i]);
            recur(ind+1, ans, nums);
            swap(nums[ind], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        recur(0, ans, nums);
        return ans;
    }
};