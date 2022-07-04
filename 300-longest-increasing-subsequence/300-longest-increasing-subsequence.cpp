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
    
    int lengthOfLIS(vector<int>& arr) 
    {
        ans= 1 ;
        for(auto i = 0; i < arr.size(); i++)
            ans = max(ans, top_down(i, arr));
        return ans;
    }
};