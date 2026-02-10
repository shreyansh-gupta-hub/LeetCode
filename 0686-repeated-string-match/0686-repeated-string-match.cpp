class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if(a==b) return 1;
        string ans = "";
        int n1 = a.size();
        int n2 = b.size();
        int count{0};
        int i = ceil(n2/ n1) + 2;
        for (int j{0}; j<i;j++){
            ans+=a;
            count++;
            size_t pos = ans.find(b);
            if(pos !=string::npos){
                return count;
            }
        }
        return -1;
    }
};