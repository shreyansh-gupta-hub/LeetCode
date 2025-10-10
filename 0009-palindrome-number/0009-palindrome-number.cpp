#include <cmath>
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        int original_x = x;
        long long reversed_x = 0;
        int digit{};
        while (x>0){
            digit = x%10;
            reversed_x = reversed_x *10 +digit;
            x = x/10;
            
        }
        return original_x == reversed_x;
    }
};