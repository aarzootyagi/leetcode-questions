class Solution {
public:
    bool sumGame(string num) {
        int n = num.size(), diff = 0, q = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') q++;
            else diff += num[i] - '0';
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') q--;
            else diff -= num[i] - '0';
        }
        if (q % 2) return true;

        return diff * 2 != -9 * q;
    }
};