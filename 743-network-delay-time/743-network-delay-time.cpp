class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define vb vector<bool>
    #define vi vector<int>
    #define pll pair<ll, ll>
    #define vpll vector<pll>
    #define vvpll vector<vpll>
    #define INF 1e9 + 7
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vvpll graph(n);
        for(auto i : times)
        {
            graph[i[0]-1].push_back({i[1]-1, i[2]});
        }
        
        vll distance(n, INF);
        set<pll> q;
        
        q.insert({0, k-1});
        distance[k-1] = 0;
        while(!q.empty())
        {
            ll u = q.begin()->second;
            q.erase(q.begin());
            for(auto it : graph[u]){
                ll v = it.first, wt = it.second;
                if(distance[v] > distance[u] + wt)
                {
                    q.erase({distance[v], v});
                    distance[v] = distance[u] + wt;
                    q.insert({distance[v], v});
                }
            }
        }
        
        ll maxi = INT_MIN;
        for(auto i : distance)
        {
            maxi = max(maxi, i);
        }
        return (maxi == INF) ? -1 : maxi;
    }
};