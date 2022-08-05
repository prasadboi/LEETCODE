class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vpll vector<pair<ll, ll>>
    #define vvll vector<vll>
    #define pll pair<ll, ll>
    #define umap unordered_map
    #define uset unordered_set
    #define MOD ((ll)(1e9 + 7))
    
    vvll vis;
    vvll grid;
    ll m, n;
    
    
    vpll nextCoord(ll x, ll y)
    {
        vpll res;
        vpll v = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(auto i : v){
            ll nx = x + i.first, ny = y + i.second;
            if(nx > -1 and nx < m and ny > -1 and ny < n and grid[nx][ny] == 1) res.push_back({nx, ny});
        }
        // for(auto i : res) cout<<i.first<<"-"<<i.second<<" || "; cout<<endl;
        return res;
    }
    
    void dfs(pll u)
    {
        vis[u.first][u.second] = 1;
        for(auto v : nextCoord(u.first, u.second)){
            if(vis[v.first][v.second] == 0) dfs(v);
        }
    }
    
    int numIslands(vector<vector<char>>& g) {
        // question is find the number of connected components
        m = g.size(), n = g[0].size();
        vis.resize(m, vll(n, 0)); grid.resize(m, vll(n, 0));
        for(auto i = 0; i < m; i++){
            for(auto j = 0; j < n; j++){
                grid[i][j] = g[i][j] - '0';
            }
        }
        
        ll res = 0;
        for(auto i = 0; i < m; i++){
            for(auto j = 0; j < n; j++){
                if(vis[i][j] == 0 and grid[i][j] == 1){
                    res++; 
                    cout<<"i = "<<i<<", j = "<<j<<endl;
                    dfs({i, j});
                }
            }
        }
        return res;
    }
};