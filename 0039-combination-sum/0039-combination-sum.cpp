class Solution {
public:
    void solve(int ind, int k, vector<int>& arr, vector<int>& res, vector<vector<int>>& ans){
        
        if(ind==arr.size()){
            if(k==0){
                ans.push_back(res);
            }
            return;
        }

        //pick
        if (arr[ind]<=k){
            res.push_back(arr[ind]);
            solve(ind,k-arr[ind],arr,res,ans );
            res.pop_back();
        }
        
        solve(ind+1,k,arr,res,ans );
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        solve(0,target,candidates,res,ans);
        return ans;
    }
};