class Solution {
    void fun(int ind, int sum, vector<int>&arr, int n, vector<int>&subsum){
        if(ind==n){
            subsum.push_back(sum);
            return;
        }
        
        fun(ind+1, sum+arr[ind], arr, n, subsum);
        fun(ind+1, sum, arr, n, subsum);
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> subsum;
        fun(0, 0, arr, n, subsum);
        return subsum;
    }
};