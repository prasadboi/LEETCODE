class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define pll pair<ll, ll>
    #define vpll vector<pll>
    #define vvpll vector<vpll>
    #define vi vector<int>
    #define vb vector<bool>
    #define spll set<pll>
    #define INF 1e9 + 7
    
    
    ll PRIM(vvpll &graph, ll n)
    {
        vll dist(n, INF), parent(n, -1);
        vb vis(n, false);
        ll cost = 0;
        spll q;
        ll src = 0;
        //-------------------------------------------------------
        vis[src] = true;
        dist[src] = 0;
        q.insert({dist[src], src});
        
        while(!q.empty())
        {
            ll u = q.begin()->second, u_wt = q.begin()->first;
            q.erase(q.begin());
            vis[u] = true;
            cost += u_wt;
            for(auto it : graph[u]){
                ll v = it.first, v_wt = it.second;
                if(vis[v]) continue;
                if(dist[v] > v_wt){
                    q.erase({dist[v], v});
                    dist[v] = v_wt;
                    q.insert({dist[v], v});
                    parent[v] = u;
                }
            }
        }
        for(auto i : dist) if(i == INF) cost = -1;
        return cost;
    }
    
    int minimumCost(int n, vector<vector<int>>& connections) 
    {
        vvpll graph(n);
        for(auto i : connections){
            graph[i[0] - 1].push_back({i[1]-1, i[2]});
            graph[i[1] - 1].push_back({i[0]-1, i[2]});
        }
        return (int) PRIM(graph, n);
    }
};