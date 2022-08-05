class Solution {
public:
    // refer : 
    // https://leetcode.com/problems/critical-connections-in-a-network/discuss/550837/Step-by-step-explanation-for-dummies
    
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define umap unordered_map
    #define uset unordered_set
    #define vvi vector<vector<int>>
    
    vvll graph;
    vll inTime, outTime, lowlink, vis;
    ll timer = 0, num_bridges;
    vvi bridges;
    
    void dfs(ll u, ll p)
    {
        inTime[u] = lowlink[u] = timer++;
        vis[u] = 1;
        for(auto v : graph[u]){
            if(!vis[v]){
                dfs(v, u);
                lowlink[u] = min(lowlink[u], lowlink[v]);
                if(lowlink[v] > inTime[u]){
                    bridges.push_back({(int)v, (int)u});
                }
            }
            if(vis[v] and v != p) // uv is a backedge
                lowlink[u] = min(lowlink[u], inTime[v]);
        }
        outTime[u]++;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        lowlink.resize(n, 0); inTime.resize(n, 0); outTime.resize(n, 0); vis.resize(n, 0);
        graph.resize(n);
        for(auto i : connections)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        dfs(0, -1);
        return bridges;
    }
};