class Solution {
public:
    int maxrow(vector<vector<int>>& mat, int n, int m, int col){
        int maxValue = -1;
        int index = -1;
        for (int i = 0;i<n;i++){
            if(mat[i][col]>maxValue){
                maxValue = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m= mat[0].size();
        int low = 0,  high = m-1;
        while(low<=high){
            int mid =(low+high)/2;
            int max = maxrow(mat, n, m, mid);
            int left = mid-1>=0 ? mat[max][mid-1] : -1;
            int right = mid+1<m ? mat[max][mid+1] : -1;
            if(mat[max][mid]>left &&mat[max][mid]>right) return {max,mid};
            else if (mat[max][mid]<left){
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        return {-1,-1};
    }
};