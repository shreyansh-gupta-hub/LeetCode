class Solution {
public:

  void par(char op,char cl,int op_cnt,int cl_cnt,vector<string>&ans,string x,int n){

    if(cl_cnt==n&&op_cnt==n){
      ans.push_back(x);
      return;
    }
    if(op_cnt<n){
      x.push_back(op);
      par(op,cl,op_cnt+1,cl_cnt,ans,x,n);
      x.pop_back();
    }

    if(cl_cnt<op_cnt){
      x.push_back(cl);
      par(op,cl,op_cnt,cl_cnt+1,ans,x,n);
      x.pop_back();
    }

  }

    vector<string> generateParenthesis(int n) {
        char op='(';
        char cl=')';
        int op_cnt=0;
        int cl_cnt=0;
        vector<string>ans;
        string x;

        par(op,cl,op_cnt,cl_cnt,ans,x,n);

        return ans;
    }
};