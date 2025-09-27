class Solution {
public:
    void permut(vector<int>& nums, vector<vector<int>>& ans, int index) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        vector<bool> use(21, 0);
        for (int i = index; i < nums.size(); i++) {
            if (use[nums[i] + 10] == 0) {
                use[nums[i] + 10] = 1;   
                swap(nums[i], nums[index]);
                permut(nums, ans, index + 1);
                swap(nums[i], nums[index]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permut(nums, ans, 0);   
        return ans;
    }
};