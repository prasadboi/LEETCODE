class Solution {
public:
    #define vvii vector<vector<int>>
    #define vll vector<long long int>>
    #define ll long long int
    #define vb vector<bool>
    #define vi vector<int>
    /*
    // THIS APPROACH GAVE ME TLE SO I LOOKED AT SOLUTION - (;_;)
    int bfs(int src, vvii &graph)
    {
        cout<<"called bfs\n";
        int n = graph.size();
        vb vis(n, false);
        queue<int> q;
        vi par(n, -1);
        q.push(src);
        vis[src] = true;
        int len = 0;
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            for(auto u : graph[v]){
                if(!vis[u] or par[u] == v)
                {
                    par[u] = v;
                    q.push(u);
                    len++;
                }
            }
        }
        return len;
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
//running a modified bfs algorithm wherein i can revisit edges , but i want to avoid revisiting cycles
        int n = graph.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            ans = min(ans, bfs(i, graph));
        }
        return ans;
    }
    */
    
    
    int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size(),res = 0;
    queue<tuple<int,int,int>> q;
    vector<vector<int>> seen(n,vector<int>(1<<n));
    for(int i=0;i<n;i++){
        q.push(tuple<int,int,int>(i,1<<i,0));
        seen[i][1<<i] = true;
    }
    while (!q.empty())
    {
        auto [idx,mask,dist] = q.front();
        q.pop();
        if(mask==(1<<n)-1){
            res = dist;
            break;
        }
        for(auto v:graph[idx]){
            int mask_v = mask|1<<v;
            if(!seen[v][mask_v]){
                q.push(tuple<int,int,int>(v,mask_v,dist+1));
                seen[v][mask_v] = true;
            }
        }
    }
    return res;
    }
};