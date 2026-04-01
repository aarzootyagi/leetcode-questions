class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h,
                                      string d) {
        int n = p.size();
        vector<tuple<int, int, char, int>> a;

        for (int i = 0; i < n; i++)
            a.push_back({p[i], h[i], d[i], i});
        sort(a.begin(), a.end());
        stack<int> st;
        vector<int> health(n);
        for (int i = 0; i < n; i++)
            health[i] = get<1>(a[i]);
        for (int i = 0; i < n; i++) {
            if (get<2>(a[i]) == 'R') {
                st.push(i);
            } else {
                while (!st.empty() && health[i] > 0) {
                    int j = st.top();
                    if (health[j] < health[i]) {
                        st.pop();
                        health[i]--;
                        health[j] = 0;
                    } else if (health[j] > health[i]) {
                        health[j]--;
                        health[i] = 0;
                        break;
                    } else {
                        health[j] = 0;
                        health[i] = 0;
                        st.pop();
                        break;
                    }
                }
            }
        }
        vector<pair<int, int>> res;
        for (int i = 0; i < n; i++) {
            if (health[i] > 0)
                res.push_back({get<3>(a[i]), health[i]});
        }
        sort(res.begin(), res.end());
        vector<int> ans;
        for (auto& x : res)
            ans.push_back(x.second);
        return ans;
    }
};