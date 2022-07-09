class Solution {
public:
    #define mpi_vpi map<pair<int, int>, vector<pair<int, int>> > 
    #define ll long long int
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector<vi>
    #define vvll vector<vll>
    #define vb vector<bool>
    #define mpi_b map<pair<int, int>, bool> 
    
    vector<pair<int, int>> get_nghbrs(pair<int, int> node, int n)
    {
        vector<pair<int, int>> res;
        int x = node.first, y = node.second;
        if(x > 0) res.push_back({x-1, y});
        if(x < n-1) res.push_back({x+1, y});
        if(y > 0) res.push_back({x, y-1});
        if(y < n-1) res.push_back({x, y+1});
        return res;
 }
    
    bool bfs(int T, int n, vvi grid)
    {
        vvi vis(n, vi(n, 0));
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        vis[0][0] = 1;
        while(!q.empty())
        {
            pair<int, int> u = q.front(); q.pop();
            if(grid[u.first][u.second] <= T)
            {
                if(u.first == n-1 and u.second == n-1) return true;
                
                for(auto v : get_nghbrs(u, n))
                {
                    if(!vis[v.first][v.second]){
                        vis[v.first][v.second] = 1;
                        q.push({v.first, v.second});
                    }
                }
            }
        }
        return false;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        // bin searching for minimum water level for which everything works
        int n = grid.size(), l = grid[0][0], r = n*n;
        int res = 0;
        while(l <= r)
        {
            int m = l + (r-l)/2;
            if(bfs(m, n, grid)){
                res = m;
                r = m-1;
            }
            else l = m+1;
        }
        return res;
    }
};