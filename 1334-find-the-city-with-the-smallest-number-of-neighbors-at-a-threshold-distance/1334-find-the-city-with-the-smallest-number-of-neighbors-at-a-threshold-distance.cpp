class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define INF (1e9 + 7)
    vvll graph;
    ll thresholdDist = 0;
    ll res = -1;
    void floydWarshall()
    {
        ll n = graph.size();
        vvll dist(n, vll(n, INF));
        for(auto i = 0; i < n; i++)
        {
            for(auto j = 0; j < n; j++)
            {
                dist[i][j] = graph[i][j];
                if(i == j) dist[i][j] = 0;
            }
        }
        
        for(auto k = 0; k < n; k++)
        {
            for(auto i = 0; i < n; i++)
            {
                for(auto j = 0; j < n; j++)
                {
                    if(dist[i][k] != INF and dist[k][j] != INF){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // for(auto i : dist){
            // for(auto j : i){
                // cout<<j<<" ";
            // }
            // cout<<endl;
        // }
        
        ll minctr = INF;
        for(auto i = 0; i < n; i++)
        {
            ll ctr = 0;
            for(auto j = 0; j < n; j++)
            {
                if(i != j and dist[i][j] <= thresholdDist) ctr++;
            }
            // cout<<"i = "<<i<<", has ctr = "<<ctr<<endl;
            if(ctr <= minctr){minctr = ctr, res = i;}
        }
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        thresholdDist = distanceThreshold;
        graph.resize(n, vll (n, INF));
        for(auto i : edges){
            graph[i[0]][i[1]] = i[2];
            graph[i[1]][i[0]] = i[2];
        }
        floydWarshall();
        return (int) res;
    }
};