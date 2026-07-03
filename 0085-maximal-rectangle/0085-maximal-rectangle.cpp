class Solution {
public:
    int largestHistogram(vector<int>& h) {
        stack<int> st;
        h.push_back(0); // dummy value 0  to flush stack
        int maxArea = 0;
        for (int i = 0; i < h.size(); i++) {
            while (!st.empty() && h[i] < h[st.top()]) {
                int height = h[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * w);
            }
            st.push(i);
        }
        h.pop_back();
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> h(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    h[j] += 1;
                else
                    h[j] = 0;
            }
            maxArea = max(maxArea, largestHistogram(h));
        }
        return maxArea;
    }
};