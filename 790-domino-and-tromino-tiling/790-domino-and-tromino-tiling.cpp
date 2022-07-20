class Solution {
public:
    
    #define ll long long int
    #define vll vector<ll>
    #define vi vector<int>
    #define umap unordered_map
    #define MOD (ll)(1e9 + 7)
    umap<ll, umap<ll, umap<ll, ll>>> dp;
    ll top_down(int n, int l, int r)
    {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(dp[n][l][r] != 0) return dp[n][l][r];
        ll res = 0;
        if(l == 0 and r == 0)
            res += top_down(n-1, 0, 0) + top_down(n-2, 0, 0) + top_down(n-2, 1, 0) + top_down(n-2, 0, 1), res = res%MOD;
        else{
            res += top_down(n-1, 0, 0);
            if(l) res += top_down(n-1, 0, 1);
            else res += top_down(n-1, 1, 0);
            res = res%MOD;
        }
        return dp[n][l][r] = res;
    }
    
    int numTilings(int n) {
        return (int)top_down(n, 0, 0);
    }
};