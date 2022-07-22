class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vi vector<int>
    #define vvll vector<vll>
    #define vvi vector<vi>
    #define umap unordered_map
    #define uset unordered_set
    
    
    vvi graph;
    umap<int, set<int>> ancestors;
    vi indegree;    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) 
    {
        graph.resize(n); indegree.resize(n, 0);
        // build graph
        for(auto i : edges) graph[i[0]].push_back(i[1]), indegree[i[1]]++;
        
        // run kahn's algo and keep track of the ancestors as well  
        queue<int> q;
        for(auto i = 0; i < n; i++) if(indegree[i] == 0) q.push(i);
        while(!q.empty())
        {
            int u = q.front(); q.pop();
            for(auto v : graph[u])
            {
                ancestors[v].insert(u);
                for(auto i : ancestors[u]) ancestors[v].insert(i);
                if(--indegree[v] == 0) q.push(v);
            }
        }
        vvi ans(n);
        for(auto i = 0; i < n; i++)
        {
            vi temp(ancestors[i].begin(), ancestors[i].end());
            ans[i] = temp;
        }
        return ans;
    }
};