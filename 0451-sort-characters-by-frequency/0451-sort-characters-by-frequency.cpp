class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        string res = "";
        for(auto i:s){
            mpp[i]++;
        }
        vector<vector<char>> bucket(s.length()+1);
        for (auto [chr, freq]:mpp) bucket[freq].push_back(chr);
        
        for (int fq = s.length(); fq>=1; fq--){
            for (auto ch: bucket[fq]){
                res.append(fq, ch);
            }
            
        }
        return res;
    }
};