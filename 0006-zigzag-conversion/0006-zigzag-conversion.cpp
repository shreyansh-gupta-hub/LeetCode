class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int l = 0;
        int ptr = l;
        string res = "";
        while (l < numRows && l < s.size())
        {
            res += s[ptr];
            int row = ptr%(numRows-1);
            int skip = 2*((numRows-1) - row);

            if (ptr + skip >= s.size())
            {
                l++;
                ptr = l;
            }
            else
            {
                ptr += skip;
            }
        }

        return res;
    }
};