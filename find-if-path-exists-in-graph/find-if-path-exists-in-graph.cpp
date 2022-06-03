class Solution {
public:
    #define vvll vector<vector<long long int>>
    bool dfs(int s, int d, vector<bool> &visited, vvll &graph)
    {
        visited[s] = true;
        if(d == s) return true;
        for(auto i : graph[s])
        {
            if(!visited[i])
            {
                if(dfs(i, d, visited, graph)) return true;
            }
                
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vvll graph(n);
        vector<bool> vis(n, false);
        for(auto i : edges)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        return dfs(s, d, vis, graph);
    }
};