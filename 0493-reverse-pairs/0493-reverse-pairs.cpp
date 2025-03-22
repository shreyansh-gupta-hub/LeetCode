class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int l = low, r = mid + 1;
        
        while (l <= mid && r <= high) {
            if (arr[l] <= arr[r]) temp.push_back(arr[l++]);
            else temp.push_back(arr[r++]);
        }
        
        while (l <= mid) temp.push_back(arr[l++]);
        while (r <= high) temp.push_back(arr[r++]);
        
        for (int i = low; i <= high; i++) arr[i] = temp[i - low];
    }

    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int r = mid + 1, cnt = 0;
        for (int i = low; i <= mid; i++) {
            while (r <= high && arr[i] > 2LL * arr[r]) r++;
            cnt += (r - (mid + 1));
        }
        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return 0;
        int mid = (low + high) / 2, cnt = 0;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
        return cnt;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};