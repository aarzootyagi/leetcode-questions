class Solution {
public:
    long long minNumberOfSeconds(int h, vector<int>& w) {
        long long l = 0, r = 1e18;

        while (l < r) {
            long long mid = (l + r) / 2;
            long long total = 0;

            for (long long t : w) {
                long long x = (sqrt(1 + 8.0 * mid / t) - 1) / 2;
                total += x;
            }

            if (total >= h)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};