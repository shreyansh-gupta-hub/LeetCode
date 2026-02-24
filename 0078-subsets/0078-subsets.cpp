class Solution {
public:
    void solve(vector<int>& s, int index, vector<int>& current, vector<vector<int>>& ans) {
        if (index == s.size()) return;  

        current.push_back(s[index]);
        ans.push_back(current);
        solve(s, index + 1, current, ans);
        current.pop_back();
        solve(s, index + 1, current, ans);
    }

    vector<vector<int>> subsets(vector<int>&  s) {
        vector<vector<int>>  ans;
        ans.push_back({});
        vector<int> current = {};
        solve(s, 0, current, ans);
        return ans;
    }
};