class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& E, vector<int>& F) {
        int n = F.size(), src= 0, dest = n-1;
        vector<vector<vector<int>>> graph(n);
        for(auto e : E)
        {
            graph[e[0]].push_back({e[1], F[e[1]], e[2]});
            graph[e[1]].push_back({e[0], F[e[0]], e[2]});
        }
        
        vector<int> time(n, -1);
        set<vector<int>> q;
        q.insert({F[src], src, 0});
        while(!q.empty())
        {
            auto i = *q.begin(); q.erase(q.begin());
            int u  = i[1], c_u = i[0], t_u = i[2];
            
            if(t_u > maxTime) continue;
            if(u == n-1) return c_u;
            if(time[u] <= t_u and time[u] != -1) continue;
            
            time[u] = t_u;
            for(auto it : graph[u])
            {
                int v = it[0], c_v = it[1], t_v = it[2];
                q.insert({c_v + c_u, v, t_v + t_u});
            }
        }
        return -1;
    }
};