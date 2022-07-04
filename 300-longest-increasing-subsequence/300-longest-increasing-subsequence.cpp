class Solution {
public:
    #define vi vector<int>
    #define ll long long int
    #define vb vector<bool>
    #define vll vector<ll>
    #define vvll vector<vll>
    #define vvi vector<vi>
    #define INF (1e9 + 7)
    
    unordered_map<ll, ll> dp_mem;
    ll ans;
    ll top_down(ll i, vi &arr)
    {
        if(dp_mem.find(i) != dp_mem.end()) return dp_mem[i];
        ll res = 1;
        for(auto j = 0; j < i; j++){
            if(arr[j] < arr[i]) res = max(res, top_down(j, arr) + 1);
        }
        // cout<<i<<" "<<res<<endl;
        return dp_mem[i] = res;
    }
    
    ll bottom_up(vi &arr)
    {
        vll dp(arr.size()+1, 1);
        dp[0] = 0;
        ll ans = 1;
        for(auto i = 1; i <= arr.size(); i++){
            for(auto j = 1; j < i; j++){
                if(arr[j-1] < arr[i-1]) dp[i] = max(dp[j]+1, dp[i]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    
    int lengthOfLIS(vector<int>& arr) 
    {
        // ans= 1 ;
        // for(auto i = 0; i < arr.size(); i++)
        //     ans = max(ans, top_down(i, arr));
        // return ans;
        return bottom_up(arr);
    }
};