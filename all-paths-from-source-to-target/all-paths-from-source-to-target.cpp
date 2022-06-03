class Solution {
public:
    
    void dfs(int s, int d, vector<vector<int>> &ans, vector<int> path, vector<bool> visited, vector<vector<int>> &graph)
    {
        path.push_back(s);
        if(s == d) ans.push_back(path);
        visited[s] = true;
        for(auto i : graph[s])
        {
            if(!visited[i]) dfs(i, d, ans, path, visited, graph);
        }
        visited[s] = false;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> ans;
        vector<bool> visited(graph.size(), false);
        vector<int> path;
        dfs(0, graph.size()-1, ans, path, visited, graph);
        return ans;
    }
};