class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mapS[256] = {0}; 
        int mapT[256] = {0};

        for (int i = 0; i < s.size(); i++) {
            if (mapS[s[i]] != mapT[t[i]]) return false;
            mapS[s[i]] = mapT[t[i]] = i + 1; // store index+1 to avoid 0 confusion
        }

        return true;
    }
};