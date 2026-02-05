class Solution {
public:
    int findmax(vector<int>& arr){
            int maxi = INT_MIN;
            for (auto i : arr){
                if(i>maxi) maxi = i;
            }
            return maxi;
    }
    long long caltotalhours(vector<int>& piles, int h){
        long long totalhours{0};
        for(auto i:piles){
            totalhours += ceil((double)i/(double)h);
        }
        return totalhours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findmax(piles);
        while(low<=high){
            int mid = low + (high-low)/2;
            long long totalh = caltotalhours(piles,mid);
            if(totalh<=h){
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};