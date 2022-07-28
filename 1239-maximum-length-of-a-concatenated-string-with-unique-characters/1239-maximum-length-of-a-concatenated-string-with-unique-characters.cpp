class Solution {
public:
    #define umap unordered_map
    #define ll long long int
    #define uset unordered_set
    
    umap<ll, umap<ll, ll>> dp;
    
    ll top_down(ll i, ll mask, vector<string> &arr)
    {
        if(i == -1) return 0;
        if(dp[i][mask] != 0) return dp[i][mask];
        bool hasDup = false;
        int currmask = 0;
        for(auto j : arr[i])
        {
            int x = j - 'a';
            if(((mask&(1<<x)) == (1<<x)) or ((currmask&(1<<x)) == (1<<x))) hasDup = true;
            currmask = currmask|(1<<x);
        }
        
        ll res = 0;
        if(hasDup == false) res = max(res, top_down(i-1, mask|currmask, arr) + (ll)arr[i].size());
        res = max(res, top_down(i-1, mask, arr));
        return dp[i][mask] = res;
    }
    
    int maxLength(vector<string>& arr) 
    {
        return top_down(arr.size()-1, 0, arr);
    }
};