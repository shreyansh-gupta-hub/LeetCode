class Solution {
public:
    int numstu(vector<int> &arr, int pages){
        int stu = 1;
        int tpages = 0;
        for(auto i: arr){
            if(tpages + i<= pages){
                tpages+=i;
            }else{
                stu++;
                tpages=i;
            }
        }
        return stu;
    }
    int findPages(vector<int>& arr, int k) {
    // Write your code here.
        if(arr.size()<k) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid = low + (high-low)/2;
            int num = numstu(arr,mid);
            if(num>k){
                low = mid+1;
            }else{
                high = mid -1;
            }
        }
        return low;
}
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,k);
    }
};