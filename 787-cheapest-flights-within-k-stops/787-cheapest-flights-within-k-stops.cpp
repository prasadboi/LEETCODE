class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define pll pair<ll, ll>
    #define vvpll vector<vector<pll>>
    #define vb vector<bool>
    #define INF 1e9  +7
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) 
    {
        vvpll graph(n);
        for(auto i : flights) graph[i[0]].push_back({i[1], i[2]});
        
        set<vll> q;
        
        q.insert({0, src, 0});
        while(!q.empty())
        {
            auto it = *q.begin();
            ll d_u = it[0], u = it[1], stop = it[2];
            q.erase(q.begin());
            if(u == dest) return d_u;
            if(stop > k) continue;
            for(auto i : graph[u])
            {
                ll v = i.first, uv_wt = i.second;
                q.insert({d_u + uv_wt, v, stop+1});
            }
        }
        return -1;
    }
};