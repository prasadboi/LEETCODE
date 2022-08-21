class Solution {
public:
    
    #define ll long long int
    #define umap unordered_map
    #define vll vector<ll>
    #define vvll vector<vll>
    
    umap<ll, umap<ll, umap<ll, ll>>> dp;
    ll top_down(ll i, ll j, ll k, vector<int> &prices){
        if(j == 0) return 0;
        if(i >= prices.size()) return 0;
        if(dp.count(i) and dp[i].count(j) and dp[i][j].count(k)) return dp[i][j][k];
        ll res = 0;
        if(k == 1){
            // holding stock:
            // can either hold or sell today
            res = max(top_down(i+1, j, k, prices), top_down(i+1, j-1, 0, prices) + prices[i]);
        }
        else if(k == 0)
        {
            // not currently holding stock
            // can either buy or forego today
            res = max(top_down(i+1, j, 0, prices), top_down(i+1, j, 1, prices) - prices[i]);
        }
        return dp[i][j][k] = res;
    }
    
    ll bottom_up(vector<int> &prices)
    {
        ll n = prices.size();
        vector<vvll> dp(n+1, vvll(3, vll(2, -1)));
        for(auto i = 0; i < 3; i++) for(auto j = 0; j < 2; j++) dp[n][i][j] = 0;
        for(auto i = 0; i <= n; i++) for(auto k = 0; k < 2; k++) dp[i][0][k] = 0;
        
        for(auto i = n-1; i >= 0; i--)
        {
            for(auto j = 1; j < 3; j++)
            {
                // not holding stock
                dp[i][j][0] = max(dp[i+1][j][1] - prices[i], dp[i+1][j][0]);
                dp[i][j][1] = max(dp[i+1][j][1], dp[i+1][j-1][0] + prices[i]);
            }
        }
        return dp[0][2][0]; // on the first day i dont have any pre stock, i have j days left
    }
    
    int maxProfit(vector<int>& prices) {
        // can complete at most 2 transactions
        // aim : to find the max possible profit
        
        // states : 
            // ith day
            // j number of transactions left
            // k whether or not i am holding stock
        
        // on every day i can either buy or leave a stock(if i dont hold any)
        // or
        // sell the stock or hold it further (if i already hold some stock)
        // return top_down(0, 2, 0, prices);
        return bottom_up(prices);
    }
};