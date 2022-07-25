class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define vi vector<int>
    #define vvi vector<vi>
    #define MOD (int)(1e9+7)
    #define umap unordered_map
    
    int add(int a, int b){return (a%MOD + b%MOD)%MOD;}
    int sub(int a, int b){return (a%MOD - b%MOD + MOD)%MOD;}
    int mul(int a, int b){return (a%MOD * b%MOD)%MOD;}
    
    umap<int, umap<int, int>> dp;
    int res = 0;
    int top_down(int i, int k, int target)
    {
        if(i == 0 and target != 0) return 0;
        if(i == 0 and target == 0) return 1;
        if(dp.find(i) != dp.end() and dp[i].find(target) != dp[i].end()) return dp[i][target];
        int tot = 0;
        for(auto x = 1; x <= k; x++)
            tot = add(tot, top_down(i-1, k, target - x));
        return dp[i][target] = tot;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        return (int) top_down(n, k, target);    
    }
};