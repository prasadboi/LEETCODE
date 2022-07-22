class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define vb vector<bool>
    #define vi vector<int>
    #define vvi vector<vi>
    #define INF (1e9 +7)
    #define umap unordered_map
    #define uset unordered_set
    
    vvll graph;
    vll in, out, indegree;
    ll timer = 0;
    vll vis;
    umap<ll, uset<ll>> ancestors;
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prereqs, vector<vector<int>>& queries) 
    {
        // for each query i have to see if the course b belongs to the subgraph/ subtree of course a
        graph.resize(n); vis.resize(n, false); in.resize(n, 0); out.resize(n, 0), indegree.resize(n, 0);
        for(auto i : prereqs){
            graph[i[0]].push_back(i[1]); 
            indegree[i[1]]++;
        }
        
        queue<ll> q;
        for(auto i = 0; i < n; i++) if(indegree[i] == 0) q.push(i);
        while(!q.empty())
        {
            ll u = q.front(); q.pop();
            for(auto v : graph[u])
            {
                ancestors[v].insert(u);
                for(auto i : ancestors[u]) ancestors[v].insert(i);
                if(--indegree[v] == 0) q.push(v);
            }
        }
        
        vb res;
        for(auto q : queries){
            ll u = q[0], v = q[1];
            if(ancestors[v].find(u) != ancestors[v].end()) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};