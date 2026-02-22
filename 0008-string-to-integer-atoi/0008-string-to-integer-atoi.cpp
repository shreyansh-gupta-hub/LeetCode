class Solution {
public:
    //recursive implementation
    int helper(const string &s, int i, long long num, int sign) {
    if (i >= s.size() || !isdigit(s[i]))
        return (int)(sign * num);
    num = num * 10 + (s[i] - '0');
    if (sign * num <= INT_MIN) return INT_MIN;
    if (sign * num >= INT_MAX) return INT_MAX;
    return helper(s, i + 1, num, sign);
}
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long res = 0;
        while (i < s.size() && s[i] == ' ') i++;
        if (i == s.size()) return 0;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        return helper(s, i, 0, sign);
    }

};