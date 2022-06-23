class Solution {
public:
    
    #define ll long long int
    #define vll vector<ll>
    #define pll pair<ll, ll>
    #define vvpll vector<vector<pll>>
    #define vb vector<bool>
    #define INF 1e9  +7
    
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) 
//     {
//         vvpll graph(n);
//         for(auto i : flights) graph[i[0]].push_back({i[1], i[2]});
        
//         set<vll> q;
        
//         q.insert({0, src, 0});
//         while(!q.empty())
//         {
//             auto it = *q.begin();
//             ll d_u = it[0], u = it[1], stop = it[2];
//             q.erase(q.begin());
//             if(u == dest) return d_u;
//             if(stop > k) continue;
//             for(auto i : graph[u])
//             {
//                 ll v = i.first, uv_wt = i.second;
//                 q.insert({d_u + uv_wt, v, stop+1});
//             }
//         }
//         return -1;
//     }
    
    
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) 
    {
        vvpll graph(n);
        for(auto i : flights) graph[i[0]].push_back({i[1], i[2]});
        
        // auto cmp = [](const vll &a, const vll &b){return a[0] <= b[0];};
        // set<vll, decltype(cmp)> q(cmp);
        set<vll> q;
        q.insert({0, 0, src}); // {dist, number of stops, node}
        while(!q.empty())
        {
            auto it1 = *q.begin();
            for(auto i : it1) cout<<i<<" "; cout<<endl;
            ll u = it1[2],stop = it1[1], d_u = it1[0];
            q.erase(q.begin());
            if(u == dest) return d_u;
            if(stop > k) continue;
            for(auto it2 : graph[u]){
                ll v = it2.first, uv_wt = it2.second;
                q.insert({d_u + uv_wt, stop + 1, v});
            }
        }
        return -1;
    }
};












