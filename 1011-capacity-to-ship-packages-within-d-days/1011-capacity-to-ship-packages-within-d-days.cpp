class Solution {
public:
    int arrsum(vector<int>& weights){
        int sum = 0;
        for (auto i : weights){
            sum+=i;
        }
        return sum;
    }
    bool numdays(vector<int>& weights, int days, int cap){
        int days_used = 1;
        int sum = 0;

        for (int w : weights) {
            if (w > cap) return false;

            if (sum + w <= cap) {
                sum += w;
            } else {
                days_used++;
                sum = w;
            }
        }

        return days_used <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = arrsum(weights);
        while(low<=high){
            int mid = low + (high-low)/2;
            if(numdays(weights,days,mid) == true){
                high = mid -1;
            }else{
                low = mid +1;
            }
        }
        return low;
    }
};