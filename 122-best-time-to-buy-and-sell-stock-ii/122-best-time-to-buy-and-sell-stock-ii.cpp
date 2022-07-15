class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0, r = 1, profit = 0;
        for(; l < r and r < n;)
        {
            if(prices[r] < prices[r-1]) profit += (prices[r-1] - prices[l]), l = r;
            r++;
        }
        if(r-1 != l) profit += prices[r-1] - prices[l];
        return profit;
    }
};