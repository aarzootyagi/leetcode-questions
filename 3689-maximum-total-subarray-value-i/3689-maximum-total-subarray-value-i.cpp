// class Solution {
// public:
//     long long maxTotalValue(vector<int>& nums, int k) {
//         long long mx = *max_element(nums.begin(), nums.end());
//         long long mn = *min_element(nums.begin(), nums.end());

//         return 1LL * k * (mx - mn);
//     }
// };

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mx = nums[0];
        long long mn = nums[0];

        for (int x : nums) {
            if (x > mx)
                mx = x;
            if (x < mn)
                mn = x;
        }

        return (mx - mn) * 1LL * k;
    }
};