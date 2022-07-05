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
        if(i == prices.size() or rem_transactions == 0) return 0;
        if(dp[i][rem_transactions][hold_stock] != 0) return dp[i][rem_transactions][hold_stock];
        if(hold_stock == 1) return dp[i][rem_transactions][hold_stock] = (int)max(top_down(i+1, rem_transactions, 1, k, prices), prices[i] + top_down(i+1, rem_transactions-1, 0, k, prices));
        else return dp[i][rem_transactions][hold_stock] = (int)max(top_down(i+1, rem_transactions, 0, k, prices), top_down(i+1, rem_transactions, 1, k, prices) - prices[i]);
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
        
        return (int)top_down(0, (ll)k, 0, (ll)k, prices);
    }
};