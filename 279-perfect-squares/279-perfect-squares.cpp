class Solution {
public:
    #define ll long long int
    #define umap unordered_map
    
    umap<ll, ll> dp;
    int numSquares(int n) {
        if(n == 0) return 0;
        if(dp[n] != 0) return dp[n];
        ll res = INT_MAX;
        for(auto i = 1; i*i <= n; i++)
            res = min(res, (ll)1 + numSquares(n-(i*i)));
        return (int) (dp[n] = res);
    }
};