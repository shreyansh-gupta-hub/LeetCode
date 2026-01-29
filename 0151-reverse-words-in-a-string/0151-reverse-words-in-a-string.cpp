class Solution {
public:
    string reverseWords(string s) {
        string result;
        string temp = "";
        for (int i = s.size()-1; i>=0; i-- ){
            if(s[i] != ' ' ){
                temp = s[i] + temp;
            }else{
                if (!temp.empty()) {
                    if (!result.empty()) result += " ";
                    result += temp;
                    temp.clear();
                }
            }
        }
        //handle the last word if any is left
        if (!temp.empty()) {
            if (!result.empty()) result += " ";
            result += temp;
        }
        return result;
    }
};