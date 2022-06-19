class Solution {
public:
    #define vi vector<int>
    #define vvi vector<vi>
    #define INF 1e15
    #define vvpll vector<vector<pair<ll, ll>>>
    #define ll long long 
    #define vll vector<ll>
    vll dijkstra(ll src, vvpll graph)
    {
        int n = graph.size();
        vll parent(n, -1), dist(n, INF);
        set<pair<int, int>> q;
        
        dist[src] = 0;
        q.insert({dist[src], src});
        while(!q.empty())
        {
            int u = q.begin()->second;
            q.erase(q.begin());
            for(auto i : graph[u])
            {
                int v = i.first, uv_wt = i.second;
                if(dist[v] > dist[u] + uv_wt){
                    q.erase({dist[v], v});
                    dist[v] = dist[u] + uv_wt;
                    q.insert({dist[v], v});
                    parent[v] = u;
                }
            }
        }
        // for(auto i : dist) cout<<i<<" "; cout<<endl;
        return dist;
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) 
    {
        vvpll graph(n), graph_rev(n);
        for(auto i : edges){
            graph[i[0]].push_back({i[1], i[2]});
            graph_rev[i[1]].push_back({i[0], i[2]});
        }
        vll paths1 = dijkstra(src1, graph);
        vll paths2 = dijkstra(src2, graph);
        vll pathd = dijkstra(dest,graph_rev);
        
        ll res = INF;
        for(int i = 0; i < n; i++)
        {
            if(paths1[i] != INF and paths2[i] != INF and pathd[i] != INF)res = min(res,(ll) paths1[i] + paths2[i] + pathd[i]);
        }
        return (res == INF) ? -1 : res;
    }
};