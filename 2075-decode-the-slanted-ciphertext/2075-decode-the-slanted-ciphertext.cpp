class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        if (rows == 1)
            return s;

        int n = s.size();
        int cols = n / rows;
        string res = "";

        for (int c = 0; c < cols; c++) {
            int i = 0, j = c;
            while (i < rows && j < cols) {
                res += s[i * cols + j];
                i++, j++;
            }
        }
        while (!res.empty() && res.back() == ' ')
            res.pop_back();
        return res;
    }
};