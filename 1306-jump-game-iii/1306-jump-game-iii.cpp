class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define umap unordered_map
    #define uset unordered_set
    #define vi vector<int>
    #define vb vector<bool>
    vvll graph;
    vll indegree;
    bool bfs(ll start, vi &arr)
    {
        ll n = graph.size();
        queue<ll> q;
        vb vis(n, false);
        q.push(start);
        while(!q.empty())
        {
            ll u = q.front();
            q.pop();
            if(arr[u] == 0) return true;
            for(auto v : graph[u]){
                if(!vis[v]){vis[v] = true; q.push(v);}
            }
        }
        return false;
    }
    
    bool canReach(vector<int>& arr, int start) {
        ll n = arr.size();
        graph.resize(n);
        indegree.resize(n, 0);
        for(auto i = 0; i < n; i++)
        {
            if(arr[i] + i < n){graph[i].push_back(arr[i] + i); indegree[arr[i]  +i]++;}
            if(i - arr[i] > -1){graph[i].push_back(i - arr[i]); indegree[i - arr[i]]++;}
        }
        return bfs(start, arr);
    }
};