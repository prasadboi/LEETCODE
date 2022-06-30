class Solution {
public:
    #define vi vector<int>
    #define ll long long int
    #define pll pair<ll, ll>
    #define vpll vector<pll>
    #define vll vector<ll>
    #define vvll vector<vll>
    #define vb vector<bool>
    #define INF (1e9 + 7)
    
    vll dp, last;
    vvll graph;
    int dfs(vector<int>& nums, ll i, ll parent, ll &ids) 
    {
        ll id = ids++, res = nums[i];
        for (auto j : graph[i])
            if (j != parent)
                res ^= dfs(nums, j, i, ids);
        last[id] = ids;
        return dp[id] = res;    
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges)
    {
        ll ids = 0, res = INT_MAX;
        ll n = nums.size();
        dp.resize(n, 0);
        last.resize(n);
        graph.resize(n);
        
        for (auto &e :  edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        int all = dfs(nums, 0, -1, ids);
        
        // this last[] implementation is new to me
        for (int i = 1; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                ll p1 = j < last[i] ? all ^ dp[i] : all ^ dp[i] ^ dp[j];
                ll p2 = j < last[i] ? dp[i] ^ dp[j] : dp[i];
                res = min(res, max({p1, p2, dp[j]}) - min({p1, p2, dp[j]}));
            }
        return res;
    }
};