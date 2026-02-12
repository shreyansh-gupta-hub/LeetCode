class Solution {
public:

    vector<int> rowAndMaximumOnes(vector<vector<int>>& arr) {
        int n1 = arr[0].size();
        int n2 = arr.size();
        int maxidx{0};
        int max = 0;
        int sum{0};
        
        for (int i{0};i<n2;i++){
            sum = 0;
            for(int j{0}; j<n1;j++){
                if(arr[i][j]==1){
                    sum++;
                }
            }
            if(sum>max){
                    max = sum;
                    maxidx = i;
                }
        }
        
        return {maxidx,max};
    }
};