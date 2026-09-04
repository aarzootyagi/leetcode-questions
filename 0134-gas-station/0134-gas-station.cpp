class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int idx = 0;
        int t = 0, tank = 0;

        for (int i = 0; i < n; i++) {
            t += gas[i] - cost[i];
            tank += gas[i] - cost[i];

            if (tank < 0) {
                idx = i + 1;
                tank = 0;
            }
        }
        if(t>=0) return idx;
        else return -1;
    }
};