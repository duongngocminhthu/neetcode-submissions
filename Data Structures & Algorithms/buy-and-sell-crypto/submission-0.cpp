class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int left = 0;

        for(int right = 1; right < prices.size(); right++){
            if(prices[right] < prices[left]) left = right;
            else{
                int cur = prices[right] - prices[left];
                profit = max(cur,profit);
            }
        }

        return profit;
    }
};
