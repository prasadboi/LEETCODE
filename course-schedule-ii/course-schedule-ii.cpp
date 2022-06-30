class Solution {
public:
    #define ll long long int
    #define vi vector<int>
    #define vb vector<bool>
    #define vvi vector<vi>
    vi topOrder, indegree;
    vvi graph;
    
    vector<int> findOrder(int n, vector<vector<int>>& edges) 
    {
        graph.resize(n, {});
        indegree.resize(n, 0);
        for(auto e : edges){
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        
        ll ctr = 0;
        queue<ll> q;

        for(auto i = 0; i < n; i++) if(indegree[i] == 0) q.push(i);
        while(!q.empty())
        {
            ll u = q.front(); q.pop();
            topOrder.push_back(u);
            for(auto v : graph[u]){
                if(--indegree[v] == 0)
                {
                    q.push(v); 
                }
            }
            ctr++;
        }
        if(ctr < n) return {};
        else return topOrder;
    }
};