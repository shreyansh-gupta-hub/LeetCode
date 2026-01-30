class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;
        int count[26] = {0};
        for (auto i:s){
            count[i-'a']++; 
        }
        for (auto j:t){
            count[j-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i]!=0) return false;
        }
        return true;
    }
};