// class Solution {
// public:
//     bool isPalindrome(string& s, int start, int end) {
//         while (start < end) {
//             if (s[start] != s[end])
//                 return false;
//             start++;
//             end--;
//         }
//         return true;
//     }
//     int solve(string& s, int start) {
//         if (start == s.size())
//             return 0;
//         int minCuts = INT_MAX;

//         for (int end = start; end < s.size(); end++) {
//             if (isPalindrome(s, start, end)) {
//                 int cuts = 1 + solve(s, end + 1);
//                 minCuts = min(minCuts, cuts);
//             }
//         }
//         return minCuts;
//     }
//     int minCut(string s) {
//         return solve(s, 0) - 1; 
//     }
// };



//memoization
class Solution {
public:
    vector<int> dp;
    vector<vector<int>> pal;

    bool isPalindrome(string &s, int i, int j) {
        if (i >= j) return true;
        if (pal[i][j] != -1) return pal[i][j];
        return pal[i][j] = (s[i] == s[j] && isPalindrome(s, i + 1, j - 1));
    }

    int solve(string &s, int i) {
        if (i == s.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int ans = INT_MAX;

        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(s, i, j)) {
                ans = min(ans, 1 + solve(s, j + 1));
            }
        }

        return dp[i] = ans;
    }

    int minCut(string s) {
        int n = s.size();
        dp = vector<int>(n, -1);
        pal = vector<vector<int>>(n, vector<int>(n, -1));
        return solve(s, 0) - 1;
    }
};