class Solution {
public:
    int countPartitions(vector<int>& arr, int maxSum) {
        int n = arr.size();
        int partitions = 1;
        int subArraySum = 0;
        for (int i = 0; i < n; i++) {
            if (subArraySum + arr[i] <= maxSum) {
                subArraySum += arr[i];
            } else {
                partitions++;
                subArraySum = arr[i];
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            int mid = (low + high) / 2;
            int partitions = countPartitions(nums, mid);
            if (partitions > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};