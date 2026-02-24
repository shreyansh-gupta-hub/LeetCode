class Solution {
public:
    void stringRecur(int i,string& s, vector<string>& ans){
        if(i>=s.length()){
            ans.push_back(s);
            return;
        }
        
        stringRecur(i+1,s,ans);

        s[i] = '0';
        stringRecur(i+2,s,ans);

        s[i]='1';
        return;
    }

    vector<string> validStrings(int N) {
        string s(N,'1');
        vector<string> ans;
        stringRecur(0,s,ans);
        return ans;
    }

};