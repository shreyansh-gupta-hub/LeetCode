class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res,vector<int>& curr, int ind){
        res.push_back(curr);
        for (int i = ind; i < nums.size(); i++) {
            if (i > ind && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            solve(nums, res, curr, i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        solve(nums,res,curr,0);
        return res;
    }
};