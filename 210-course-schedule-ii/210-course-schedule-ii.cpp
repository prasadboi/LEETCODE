class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define vb vector<bool>
    #define vi vector<int>
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        ll n = numCourses;
        
        // gen graph
        vvll graph(n);
        vll indegree(n, 0);
        for(auto i : prerequisites)
        {
            graph[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        
        // Kahn's algorithm
        queue<ll> q;
        vi topOrder; 
        ll ctr = 0;
        for(int i = 0; i < n; i++)
            if(indegree[i] == 0) q.push(i);
        while(!q.empty())
        {
            ll u = q.front(); q.pop();
            topOrder.insert(topOrder.begin(), (int)u);
            for(auto v : graph[u])
                if(--indegree[v] == 0) q.push(v);
            ctr++;
        }
        if(ctr != n) return {}; else return topOrder;
    }
};