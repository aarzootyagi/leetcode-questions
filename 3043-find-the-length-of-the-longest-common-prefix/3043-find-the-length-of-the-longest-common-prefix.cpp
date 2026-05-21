class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> s;

        for (int x : arr1) {
            string t = to_string(x), p = "";
            for (char c : t) {
                p += c;
                s.insert(p);
            }
        }
        int ans = 0;
        for (int x : arr2) {
            string t = to_string(x), p = "";
            for (char c : t) {
                p += c;
                if (s.count(p))
                    ans = max(ans, (int)p.size());
            }
        }
        return ans;
    }
};