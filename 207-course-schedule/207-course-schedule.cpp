class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define vb vector<bool>
    #define vi vector<int>
    
    bool canFinish(int num, vector<vector<int>>& prerequisites) 
    {
        ll n = num;
        vvll graph(n); vll outdegree(n, 0), indegree(n, 0);
        for(auto i : prerequisites){
            graph[i[0]].push_back(i[1]);
            indegree[i[1]]++, outdegree[i[0]]++;
        }
        
        // Kahn's algorithm
        // find the start nodes
        queue<int> q;
        ll ctr = 0;
        for(ll i = 0; i < n; i++){
            if(indegree[i] == 0){q.push(i);}
        }
        
        while(!q.empty())
        {
            ll u = q.front();
            q.pop();
            for(auto v : graph[u])
            {if(--indegree[v] == 0) {q.push(v);}}
            ctr++;
        }
        if(ctr != n) return false; else return true;
    }
};