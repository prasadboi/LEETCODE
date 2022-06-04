class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &visited, int i, int dest) 
    {
        if (graph[i].empty()) return i == dest;
        if (visited[i] != -1) return visited[i];
        visited[i] = 0;
        for (auto j : graph[i])
            if (!dfs(graph, visited, j, dest)) return false;
        return visited[i] = true;
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<vector<int>> graph(n);
        vector<int> visited(n, -1);
        for (auto e : edges) graph[e[0]].push_back(e[1]);
        return dfs(graph, visited, source, destination);
    }
};