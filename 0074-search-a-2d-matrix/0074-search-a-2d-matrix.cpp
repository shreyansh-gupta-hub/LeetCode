class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n = arr.size();
        int m = arr[0].size();
        if(arr.size()==0) return false;
        int low{0};
        int high = (n*m)-1;
        while(low<= high){
            int mid = (low+high)/2;
            int i = mid/m;
            int j = mid%m;
            if(arr[i][j]==target) return true;
            else if(arr[i][j]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return false;
    }
};