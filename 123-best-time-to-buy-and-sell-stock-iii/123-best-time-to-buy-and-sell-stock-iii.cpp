class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define umap unordered_map
    #define vb vector<bool>
    #define vi vector<int>
    
    
    // i : the current day
    // j : the number of transactions completed
    // k : whether we are holding stock currently or not
    // top_down(i, j) : the maximum profit made when we have completed i days and j transactions
    
    umap<ll, umap<ll, umap<bool, ll>>> dp;
    
    ll top_down(ll i, ll j, bool hold, vi &prices){
        if(i >= prices.size()) return 0;
        if(j <= 0) return 0;
        if(dp[i][j][hold] != 0) return dp[i][j][hold];
        ll res = 0;
        if(hold == true){
            // can either sell or hold on to it
            res = max(top_down(i+1, j-1, false, prices) + prices[i], top_down(i+1, j, true, prices));
        }
        else{
            // can either buy or not buy
            res = max(top_down(i+1, j, true, prices) - prices[i], top_down(i+1, j, false, prices));
        }
        // cout<<"i = "<<i<<", j = "<<j<<", hold = "<<hold<<"top down = "<<res<<endl;
        return dp[i][j][hold] = res;
    }
    
    ll bottom_up(vi &prices)
    {
        ll n = prices.size();
        vector<vvll> dp(n+1, vvll (3, vll(2, 0)));
        for(auto i = n-1; i >= 0; i--)
        {
            for(auto j = 2; j > 0; j--)
            {
                
                (dp[i][j][1] = max(dp[i+1][j][1], dp[i+1][j-1][0] + prices[i]));
                (dp[i][j][0] = max(dp[i+1][j][0], dp[i+1][j][1] - prices[i]));
            }
        }
        return dp[0][2][0];
    }
    
    int maxProfit(vector<int>& prices) {
        ll n = prices.size(), maxTransactions = 2;
        // return top_down(0, 2, false, prices);
        return bottom_up(prices);
    }
};