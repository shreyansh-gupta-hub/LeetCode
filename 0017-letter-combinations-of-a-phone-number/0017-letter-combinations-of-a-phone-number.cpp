class Solution {
public:
    
    void comb(vector<string> st,int index,string digits,string test,vector<string>& result){
        if(index==digits.length()){
            result.push_back(test);
            return;
        }
        char char1 = digits[index];
        int ind=(char1-'0')-1;
        string temp = st[ind],temp2 = test;
        for(int i=0;i<temp.length();i++){
            test+=temp[i];
            comb(st,index+1,digits,test,result);
            test=temp2;
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> st= {"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result;
        if(digits==""){
            return result;
        }
        comb(st,0,digits,"",result);
        return result;
    }
};