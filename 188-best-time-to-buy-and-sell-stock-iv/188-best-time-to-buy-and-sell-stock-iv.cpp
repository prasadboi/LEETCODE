class Solution {
public:
    #define ll long long int
    #define vi vector<int>
    #define vvi vector<vi>
    #define umapi_i unordered_map<int, int>
    #define umapi_umapi_i unordered_map<int, umapi_i>
    #define umapi_umapi_umapi_i unordered_map<int, umapi_umapi_i>
    
    umapi_umapi_umapi_i dp;
    int top_down(ll i, ll rem_transactions, ll hold_stock, ll k, vi &prices)
    {
        // base cases
        if(i == prices.size() or rem_transactions == 0) return 0;
        // memoization step
        if(dp[i][rem_transactions][hold_stock] != 0) 
            return dp[i][rem_transactions][hold_stock];
        if(hold_stock == 1) // if you have stock then you can either sell it on day i or keep on holding to it
            return dp[i][rem_transactions][hold_stock] = (int)max(top_down(i+1, rem_transactions, 1, k, prices), prices[i] + top_down(i+1, rem_transactions-1, 0, k, prices));
        else // if you dont have any stock on day i, you can buy the stock on day i or do nothing
            return dp[i][rem_transactions][hold_stock] = (int)max(top_down(i+1, rem_transactions, 0, k, prices), top_down(i+1, rem_transactions, 1, k, prices) - prices[i]);
    }
    
    int bottom_up(ll k, vi &prices)
    {
        ll n = prices.size();
        vector<vvi> dp(n+1, vvi (k+1, vi (2, 0)));
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = 1; j <= k; j++)
            {
                dp[i][j][0] = max(dp[i+1][j][1] - prices[i], dp[i+1][j][0]);
                dp[i][j][1] = max(dp[i+1][j-1][0] + prices[i], dp[i+1][j][1]);
            }
        }
        return (int)dp[0][k][0];
    }
    
    int maxProfit(int k, vector<int>& prices) 
    {
        // find max profit you can achieve using atmost k transcations
        
        // states:
            // 1. 'i' : the ith day
            // 2. 'rem_tran' : rem_tran number of transactions left
            // 3. 'bool' : whether we are holding any stock or not (boolean state)
        /* 
        dp(i, rem_tran, bool) : the max profit i can gain starting on day i
        with allowed number of transactions = rem_tran 
        and whether or not i currently hold stock
        */
        
        // return (int)top_down(0, (ll)k, 0, (ll)k, prices);
        return bottom_up((ll)k, prices);
    }
};