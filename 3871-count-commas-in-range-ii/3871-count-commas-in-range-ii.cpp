// class Solution {
// public:
//     long long countCommas(long long n) {
//         long long ans = 0;
//         long long base = 1000;
//         int commas = 1;
//         while(base <= n){
//             long long next = base*1000 - 1;
//             long long end = min(n, next);
//             ans += (end - base +1) * commas;
//             base *= 1000;
//             commas++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0, p = 1000;
        while (p <= n) {
            ans += n - p + 1;
            p *= 1000;
        }
        return ans;
    }
};