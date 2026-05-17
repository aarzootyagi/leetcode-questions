class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (i < 0 || i >= arr.size() || arr[i] < 0)
                continue;
            if (arr[i] == 0)
                return true;

            int jump = arr[i];
            arr[i] = -arr[i];

            q.push(i + jump);
            q.push(i - jump);
        }
        return false;
    }
};