class Solution {
public:
    #define ll long long int
    #define vi vector<int>
    #define vb vector<bool>
    #define vvi vector<vi>
    vi topOrder, indegree;
    vvi graph;
    
    void dfs(int u){
        topOrder.push_back(u);
        indegree[u]--; // so that we dont traverse u again. ever
        for(auto v : graph[u])
            if(--indegree[v] == 0) dfs(v);
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& edges) 
    {
        graph.resize(n, {});
        indegree.resize(n, 0);
        for(auto e : edges){
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        for(auto i  = 0; i < n; i++) if(indegree[i] == 0) dfs(i);
        
        if(topOrder.size() != n) return {};
        else return topOrder;

    }
};