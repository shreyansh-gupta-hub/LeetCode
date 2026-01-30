class Solution {
public:
    bool rotateString(string s, string goal) {
        bool flag = false;
        int len = s.size();
        for(int i{0}; i<len; i++){
            s = s[len-1] + s;
            s = s.substr(0,len);
            if (s == goal){
                flag = true;
                break;
            }
        }
        return flag;
    }
};