class Solution {
public:
    #define ll long long int
    #define INF (1e9 + 7)
    
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector<vi>
    #define vvll vector<vll>
    #define umap unordered_map
    #define uset unordered_set
    
    #define pub push_back
    #define pob pop_back
    #define F first()
    #define B back()
    
    int minCostII(vector<vector<int>>& costs) {
        ll n = costs.size();
        if(n == 0) return 0;
        
        ll c = costs[0].size();
        if(c == 0) return INF;
        
        vvll dp(n, vll (c, INF));
        for(auto j = 0; j < c; j++) dp[0][j] = costs[0][j];

        for(auto i = 1; i < n; i++)
            for(auto j = 0; j < c; j++){
                for(auto k = 1; k < c; k++)
                    dp[i][j] = min(dp[i][j], dp[i-1][(j + k)%c]);
                dp[i][j] += costs[i][j];
            }
        ll res = INF;
        for(auto j = 0; j < c; j++) res = min(res, dp[n-1][j]);
        return (int) res;
    }
};