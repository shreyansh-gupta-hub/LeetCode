class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long res = 0;
        // Skip leading whitespaces
        while (i < s.size() && s[i] == ' ') i++;
        // Return 0 if only spaces are found
        if (i == s.size()) return 0;
        // Check for optional '+' or '-' sign
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        // Convert characters to integer while valid digits
        while (i < s.size() && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');
            // Clamp to INT_MAX if overflow occurs
            if (sign * res > INT_MAX) return INT_MAX;
            // Clamp to INT_MIN if underflow occurs
            if (sign * res < INT_MIN) return INT_MIN;
            i++;
        }

        // Return final result after applying sign
        return (int)(sign * res);
    }

};