class Solution {
public:
    int maxarr(vector<int>& arr){
        int maxi = INT_MIN;
        for(auto i: arr){
            if(maxi<i){
                maxi = i;
            }
        }
        return maxi;
    }
    int possible(vector<int>& bloomDay, int k, int day){
        int count{0};
        int num{0};
        for (auto i :bloomDay){
            if(i<=day){
                count++;
            }else{
                num+=count/k;
                count = 0;
            }
        }
        num += count / k;
        return num;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) return -1;
        int low = 1;
        int high = maxarr(bloomDay);
        while(low<=high){
            int mid = low + (high-low)/2;
            if(possible(bloomDay, k, mid) >= m ){
                high = mid -1;
            }else{
                low = mid +1;
            }
        }
        return low;
        
    }
};