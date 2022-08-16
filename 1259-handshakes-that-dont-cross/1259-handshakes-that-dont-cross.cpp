class Solution {
public:
    #define ll long long int
    #define umap unordered_map
    #define vll vector<ll>
    #define vvll vector<vll>
    #define uset unordered_set
    #define MOD ((ll)(1e9 + 7))
    
    umap<ll, ll> dp;
    
    ll top_down(ll n)
    {
        if(n < 2) return 0;
        if(n%2 == 1) return 0;
        if(n == 2) return 1;
        
        if(dp.count(n) > 0) return dp[n];
        
        dp[n] = top_down(n-2);
        for(int k = 2; k <= n-2; k++){
            ll l = (k-2 > 0) ? top_down(k-2) : 1;
            ll r = (n-k > 0) ? top_down(n-k) : 1;
            dp[n] += (l*r); dp[n] %= MOD;
        }
        return dp[n];
    }
    int numberOfWays(int numPeople) {
        return top_down(numPeople);
    }
};