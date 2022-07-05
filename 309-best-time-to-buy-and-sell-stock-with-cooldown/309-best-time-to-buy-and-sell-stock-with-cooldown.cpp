class Solution {
public:
    #define ll long long int
    #define vi vector<int>
    #define vvi vector<vi>
    #define umapi_i unordered_map<int, int>
    #define umapi_umapi_i unordered_map<int, umapi_i>
    #define umapi_umapi_umapi_i unordered_map<int, umapi_umapi_i>
    
    umapi_umapi_i dp;
    int top_down(int i, int hold_stock, vi &prices)
    {
        if(i >= prices.size()) return 0;
        if(dp[i][hold_stock] != 0) return dp[i][hold_stock];
        if(hold_stock == 1) 
            return dp[i][hold_stock] = max(top_down(i + 1, 1, prices), prices[i] + top_down(i+2, 0, prices));
        else 
            return dp[i][hold_stock] = max(top_down(i + 1, 0, prices), -prices[i] + top_down(i+1, 1, prices));
    }
    
    int bottom_up(vi &prices)
    {
        int n = prices.size();
        vvi dp(n+2, vi (2, 0));
        for(auto i = n-1; i >= 0; i--)
        {
            dp[i][1] = max(dp[i+1][1], dp[i+2][0] + prices[i]);
            dp[i][0] = max(dp[i+1][0], dp[i+1][1] - prices[i]);
        }
        return dp[0][0];
    }
    
    int maxProfit(vector<int>& prices) {
        // return top_down(0, 0, prices);
        return bottom_up(prices);
    }
};