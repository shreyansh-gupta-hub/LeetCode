class Solution {
public:
    void solve(int ind, int k, vector<int>& arr, vector<int>& res, vector<vector<int>>& ans){
        
        if(k==0){
            ans.push_back(res);
            return;
        }
        
        for(int i = ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>k) break;
            res.push_back(arr[i]);
            solve(i+1,k-arr[i],arr,res,ans);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> res;
        solve(0,target,candidates,res,ans);
        return ans;
    }
};