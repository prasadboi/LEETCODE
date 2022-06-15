class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define vb vector<bool>
    #define vi vector<int>
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        vvll graph(n);
        vll degree(n, 0);
        for(auto i : edges)
        {
            graph[i[0]].push_back(i[1]); graph[i[1]].push_back(i[0]); 
            degree[i[1]]++; degree[i[0]]++;
        }
        
        queue<int> q;
        int nodes_left = n;
        for(int i = 0; i < n; i++) if(--degree[i] == 0) q.push(i);
        while(q.size() and nodes_left > 2)
        {
            int sz = q.size();
            for(int t = 0; t < sz; t++)
            {
                int u = q.front(); q.pop();
                for(auto v : graph[u])
                    if(--degree[v] == 0) q.push(v);
            }
            nodes_left -= sz;
        }
        vi res;
        if(n == 1) return {0};
        while(q.size()){res.push_back(q.front()); q.pop();}
        return res;
    }
};