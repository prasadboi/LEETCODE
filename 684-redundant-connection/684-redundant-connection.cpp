class Solution {
public:
    
    #define ll long long int
    #define vvll vector<vector<ll>>
    #define vvpll vector<vector<pair<ll, ll>>>
    #define vll vector<ll>
    #define vi vector<int>
    #define vb vector<bool>
    #define vc vector<char>   
    
//     -------------------------------------------------------------------------------------------------
    
    vvll graph;
    vll parent;
    vb visited;
    unordered_set<int> cycle;
    int cycle_start = -1, cycle_end = -1;
    
    bool dfs(int src)
    {
        visited[src] = true;
        for(auto i : graph[src])
        {
            if(parent[src] == i) continue;
            if(visited[i])
            {
                cycle_start = i;
                cycle_end = src; 
                return true;
            }
            parent[i] = src;
            if(dfs(i)) return true;
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        graph.resize(n);
        visited.resize(n, false);
        parent.resize(n, -1);
        vi ans;
        for(auto i : edges)
        {
            graph[i[1]-1].push_back(i[0]-1);
            graph[i[0]-1].push_back(i[1]-1);
        }
        if(dfs(0)){
            for(int u = cycle_end; u != cycle_start; u = parent[u])
            {
                cycle.insert(u);
            }
            cycle.insert(cycle_start);
            
            for(int i = n-1; i > -1; i--)
            {
                if(cycle.count(edges[i][0]-1)and cycle.count(edges[i][1]-1)){ans = edges[i]; break;}
            }
        }
        return ans;
    }
};