class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define MOD ((ll)(1e9 + 7))
    #define umap unordered_map
    #define uset unordered_set
    
    
    
    vll last_occur;
    umap<ll, ll> dp;
    ll top_down(ll i, string &s)
    {
        if(i == -1) return 1;
        if(dp.count(i) > 0) return dp[i];
        ll res = 0;
        res += ((2%MOD)*(top_down(i-1, s))%MOD)%MOD;
        if(last_occur[s[i] - 'a'] >= 0) 
            res = (res - top_down(last_occur[s[i] - 'a']-1, s))%MOD + MOD;
        res%=MOD;
        
        last_occur[s[i] - 'a'] = i;
        return dp[i] = res%MOD;
    }
    
    int distinctSubseqII(string s) {
        last_occur.resize(26, -1);
        return (top_down(s.size()-1, s) - 1)%MOD;
    }
};