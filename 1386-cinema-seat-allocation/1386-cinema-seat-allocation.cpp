class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for (auto& x : reservedSeats)
            mp[x[0]] |= (1 << x[1]);

        int ans = 2 * (n - mp.size());

        for (auto& [row, mask] : mp) {
            bool left = !(mask & 0b0000111100);
            bool mid = !(mask & 0b0011110000);
            bool right = !(mask & 0b1111000000);

            if (left && right)
                ans += 2;
            else if (left || mid || right)
                ans++;
        }

        return ans;
    }
};