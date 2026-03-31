class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string res(n + m - 1, '?');
        vector<bool> fixed(n + m - 1, false);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (res[i + j] == '?' || res[i + j] == str2[j]) {
                        res[i + j] = str2[j];
                        fixed[i + j] = true; 
                    } else {
                        return "";
                    }
                }
            }
        }
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == '?') res[i] = 'a';
        }
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;

                for (int j = 0; j < m; j++) {
                    if (res[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    bool fixedFlag = false;
                    for (int j = m - 1; j >= 0; j--) {
                        int idx = i + j;

                        if (fixed[idx]) continue; 
                        char original = res[idx];
                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c == original) continue;
                            res[idx] = c;
                            bool stillMatch = true;
                            for (int k = 0; k < m; k++) {
                                if (res[i + k] != str2[k]) {
                                    stillMatch = false;
                                    break;
                                }
                            }
                            if (!stillMatch) {
                                fixedFlag = true;
                                break;
                            }
                        }
                        if (fixedFlag) break;
                        res[idx] = original;
                    }
                    if (!fixedFlag) return "";
                }
            }
        }
        return res;
    }
};