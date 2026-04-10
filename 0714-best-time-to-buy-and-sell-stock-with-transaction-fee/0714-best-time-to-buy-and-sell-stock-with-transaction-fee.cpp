class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        int hold = -prices[0]; 
        int cash = 0;        
        
        for(int i = 1; i < n; i++){
            int prevHold = hold;
            hold = max(hold, cash - prices[i]);
            cash = max(cash, prevHold + prices[i] - fee);
        }
        return cash;
    }
};