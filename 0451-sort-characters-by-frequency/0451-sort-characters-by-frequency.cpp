class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        string res = "";
        for(auto i:s){
            mpp[i]++;
        }
        vector<pair<char, int>> freqArr;
        for (auto [chr, freq]:mpp) freqArr.push_back({chr,freq});
        
        auto cmp = [&](pair<char, int>& a, pair<char,int>& b){
            return a.second> b.second;
        };
        sort(freqArr.begin(),freqArr.end(), cmp);

        for (auto [ch,fq]:freqArr){
            res.append(fq,ch);
        }
        return res;
    }
};