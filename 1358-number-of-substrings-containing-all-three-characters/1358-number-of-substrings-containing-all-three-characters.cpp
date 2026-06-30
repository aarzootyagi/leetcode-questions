class Solution {
public:
    int numberOfSubstrings(string s) {
        int abc[3] = {-1 , -1 , -1};
        int count = 0 , right = 0;
        while(right < s.size()){
            abc[s[right] - 'a'] = right;
            int minIdx = INT_MAX;
            for(int i=0; i<3; i++){
                minIdx = min(minIdx , abc[i]);
            }
            count += (minIdx +1);
            right++;
        }
        return count;
    }
};