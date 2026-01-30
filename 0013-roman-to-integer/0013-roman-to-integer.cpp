class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> lst = { {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int res{0};
        for (int i{0}; i<s.size()-1;i++){
            if (lst[s[i]] < lst[s[i + 1]]) {
                res -= lst[s[i]];
            } else {
                res += lst[s[i]];
            }

        }
        return res + lst[s.back()];//because we didn't take the last value in the loop
    }
};