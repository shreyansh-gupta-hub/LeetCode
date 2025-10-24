class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num = nums.size();
        unordered_map<int, int> mpp;
        for(auto i: nums){
            mpp[i]++;
        }
        vector<int> res;
        for (auto& [key, value]: mpp){
            if (value> num/3){
                res.push_back(key);
            }
        }
        return res;
    }
};