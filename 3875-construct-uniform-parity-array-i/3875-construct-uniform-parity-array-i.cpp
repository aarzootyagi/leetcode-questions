class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0;
        for (int x : nums1)
            if (x % 2) odd++;
            
        bool possible_even = (odd != 1);
        bool possible_odd = (odd >= 1);

        return possible_even || possible_odd;
    }
};