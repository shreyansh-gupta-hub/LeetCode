class Solution {
public:
    int maxele(vector<int>& nums){
        int max = INT_MIN;
        for (auto i: nums){
            if(max<i) max = i;
        }
        return max;
    }
    bool possible(vector<int>& nums, int threshold, int  div){
        int sum{0};
        for(auto i : nums){
            sum+=ceil((double)i/div);
        }
        if(sum<=threshold){
            return true;
        }
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int high = maxele(nums);
        int low = 1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(possible(nums,threshold,mid)==true){
                high = mid -1;
            }else{
                low = mid +1;
            }
        }
        return low;
    }
};