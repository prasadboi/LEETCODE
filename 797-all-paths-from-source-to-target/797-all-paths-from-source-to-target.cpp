class Solution {
public:
//     ------------------------------------------------------------------------------------------------------------------
//     via dfs
    
    // void dfs(int s, int d, vector<vector<int>> &ans, vector<int> path, vector<bool> visited, vector<vector<int>> &graph)
    // {
    //     path.push_back(s);
    //     if(s == d) ans.push_back(path);
    //     visited[s] = true;
    //     for(auto i : graph[s])
    //     {
    //         if(!visited[i]) dfs(i, d, ans, path, visited, graph);
    //     }
    //     visited[s] = false;
    // }
//     ------------------------------------------------------------------------------------------------------------------
//     via bfs
    
    void bfs(int src, int dest, vector<vector<int>> &ans, vector<int> path, vector<bool> visited, vector<vector<int>> &graph)
    {
        // as it is a directed graph, we do not need to use the visited array
        // queue here will maintain the paths
        queue<vector<int>> q;
        
        path = {src};
        q.push(path);
        while(!q.empty())
        {
            path = q.front(); q.pop();
            int currNode = path[path.size() - 1];
            if(currNode == dest)
                ans.push_back(path);
            else
            {
                for(auto i : graph[currNode])
                {
                    vector<int> temp(path.begin(), path.end());
                    temp.push_back(i);
                    q.push(temp);
                }
            }
        }
    }
 //     ----------------------------------------------------------------------------------------------------------------- 
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> ans;
        vector<bool> visited(graph.size(), false);
        vector<int> path;
        // dfs(0, graph.size()-1, ans, path, visited, graph);
        bfs(0, graph.size() - 1, ans, path, visited, graph);
        return ans;
    }
};