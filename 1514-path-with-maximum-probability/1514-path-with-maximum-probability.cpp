class Solution {
public:
    #define lf double
    #define ll long long int
    #define vlf vector<lf>
    #define vvlf vector<vlf>
    #define vvplf vector<vector<pair<lf, lf>>>
    #define vb vector<bool>
    #define INF INT_MAX
    
    lf Dijkstra(int n, vvplf &graph, ll src, ll dest)
    {
        set<pair<lf, lf>> q;
        vlf dist(n, INT_MAX);
        
        dist[src] = 0;
        q.insert({dist[src], src});
        while(!q.empty())
        {
            lf u = q.begin()->second;
            lf u_d = q.begin()->first;
            q.erase(q.begin());
            for(auto i : graph[u])
            {
                lf v = i.first, uv_wt = i.second;
                if(dist[v] > dist[u] + uv_wt)
                {
                    q.erase({dist[v], v});
                    dist[v] = dist[u] + uv_wt;
                    q.insert({dist[v], v});
                }
            }
        }
        return dist[dest];
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        vvplf graph(n);
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back({edges[i][1], abs(log(succProb[i]))});
            graph[edges[i][1]].push_back({edges[i][0], abs(log(succProb[i]))});
        }
        
        // cout<<Dijkstra(n, graph, start, end)<<endl;
        return exp(-1*Dijkstra(n, graph, start, end));
    }
};