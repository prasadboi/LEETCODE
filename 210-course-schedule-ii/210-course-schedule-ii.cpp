class Solution {
public:
    #define vvll vector<vector<long long int>>
    #define vi vector<int>
    void dfs(int src, vvll &graph, vi &ans, vi &indegree)
    {
    ans.push_back(src);
    indegree[src] = -1;
    for(auto i : graph[src])
    {
        indegree[i]--;
        if(indegree[i] == 0) dfs(i, graph, ans, indegree);
    }
    }
    
    
    vector<int> findOrder(int n, vector<vector<int>>& Prereqs) {
    vvll graph(n);
    vi indegree(n,0), ans;
    for(auto i : Prereqs)
    {
        graph[i[1]].push_back(i[0]);
        indegree[i[0]]++;
    }

    for(int i = 0; i < n; i++)
    {
        if(indegree[i] == 0) dfs(i, graph, ans, indegree);
    }
    if(ans.size() == n) return ans; else return {};
    }
};