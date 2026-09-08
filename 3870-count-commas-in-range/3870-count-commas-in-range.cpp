// class Solution {
// public:
//     int countCommas(int n) {
//         long long ans = 0;
//         if (n >= 1000) {
//             ans += (min(n, 999999) - 1000 + 1);
//         }
//         if (n >= 1000000) {
//             ans += 2LL * (min(n, 999999999) - 1000000 + 1);
//         }
//         if (n >= 1000000000) {
//             ans += 3LL * (n - 1000000000 + 1);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int countCommas(int n) {
        long long ans = 0;
        long long p = 1000;

        while (p <= n) {
            ans += n - p + 1;
            p *= 1000;
        }

        return ans;
    }
};