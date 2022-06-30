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
    
    vll dp, in , out;
    vvll graph;
    ll time = 0;
    
    ll dfs(vi & nums, ll i, ll parent) 
    {
        in[i] = time++;
        ll res = nums[i];
        for (auto j : graph[i])
            if (j != parent)
                res ^= dfs(nums, j, i);
        out[i] = time++;
        return dp[i] = res;    
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges)
    {
        ll n = nums.size(), res = INF;
        dp.resize(n, 0); in.resize(n, 0); out.resize(n, 0);
        graph.resize(n);
        
        for (auto &e :  edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        ll all = dfs(nums, 0, -1);
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < n; j++)
            {
                if(i == j) continue;
                ll tree1 = INF, tree2 = INF, tree3 = INF;
                if(in[i] < in[j] and out[i] > out[j])
                    tree1 = dp[j], tree2 = dp[i]^dp[j], tree3 = all^dp[i];
                else if(in[i] > in[j] and out[i] < out[j])
                    tree1 = dp[i], tree2 = dp[j]^dp[i], tree3 = all^dp[j];
                else
                    tree1 = dp[i], tree2 = dp[j], tree3 = all^dp[i]^dp[j];
                
                res = min(res, max({tree1, tree2, tree3}) - min({tree1, tree2, tree3}));
            }
        }
        return res;
    }
};