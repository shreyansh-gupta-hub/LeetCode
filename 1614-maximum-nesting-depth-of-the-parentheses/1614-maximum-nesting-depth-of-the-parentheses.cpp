class Solution {
public:
    int maxDepth(string s) {
        int max = INT_MIN;
        int count{0};
        for(auto i:s){
            if(i=='('){
                count++;
            }
            if (count>max){
                max = count;
            }
            if(i==')'){
                count--;
            }
        }
        return max;
    }
};