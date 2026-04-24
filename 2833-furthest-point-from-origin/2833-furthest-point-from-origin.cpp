class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, blank = 0;
        for (char c : moves) {
            if (c == 'L') L++;
            else if (c == 'R') R++;
            else blank++;
        }
        int right = R + blank - L;
        int left = L + blank - R;
        return max(abs(right), abs(left));
    }
};