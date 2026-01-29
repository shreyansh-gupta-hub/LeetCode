class Solution {
public:
    string largestOddNumber(string num) {
        if (num.empty()) return "";

        string result = "";
        for(int i = num.size()-1; i>=0;i--){
            if( (num[i]-'0') % 2 != 0){
                result = num.substr(0, i+1);
                break;
            }
        }
        return result;
    }
};