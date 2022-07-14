class Solution {
public:
    #define vi vector<int>
    #define ll long long int
    #define vll vector<ll>
    #define vb vector<bool>
    #define vvll vector<vll>
    
    vvll graph;
    unordered_map<int, int> dp;
    vi ans;
    vi subtree_sum;
    vi count;
    void dfs1(int u, int p)
    {
        for(auto v : graph[u]){
            if(v != p){
                dfs1(v, u);
                count[u] += count[v];
                subtree_sum[u] += subtree_sum[v] + count[v];
            }
        }
    }
    
    void dfs2(int u, int p)
    {
        for(auto v : graph[u])
        {
            if(v != p){
                ans[v] = ans[u] - count[v] + (graph.size() - count[v]);
                dfs2(v, u);
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for(auto i : edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        count.resize(n, 1);
        ans.resize(n, 0);
        subtree_sum.resize(n, 0);
        dfs1(0, -1);
        ans[0] = subtree_sum[0];
        dfs2(0, -1);
        return ans;
    }
};