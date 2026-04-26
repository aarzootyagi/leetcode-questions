// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int i = haystack.find(needle);
//         return i == -1 ? -1 : i;
//     }
// };

class Solution {
public:
    int strStr(string h, string n) {
        for (int i = 0; i + n.size() <= h.size(); i++)
            if (h.substr(i, n.size()) == n)
                return i;
        return -1;
    }
};