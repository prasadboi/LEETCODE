class Solution {
public:
    #define vi vector<int>
    #define vvi vector<vi>
    #define vb vector<bool>
    #define vvb vector<vb>
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define vpll vector<pair<ll, ll>>
    #define umap unordered_map
    ll m, n;
    unordered_map<ll, unordered_map<ll, ll>> dp;
    unordered_map<ll, unordered_map<ll, bool>> vis;
    
    
    vpll get_next(ll i, ll j, vvi &matrix)
    {
        vpll nxt;
        ll curr = (ll) matrix[i][j];
        if(i > 0 and matrix[i-1][j] > curr) nxt.push_back({i-1, j});
        if(j > 0 and matrix[i][j-1] > curr) nxt.push_back({i, j-1});
        if(i < m-1 and matrix[i+1][j] > curr) nxt.push_back({i+1, j});
        if(j < n-1 and matrix[i][j+1] > curr) nxt.push_back({i, j+1});
        return nxt;
    }
    
    ll dfs(vvb &vis, vvi &matrix, ll i, ll j)
    {
        // cout<<"at node : "<<i<<" - "<<j<<endl;
        vis[i][j] = true;
        if(dp[i][j] != 0) return dp[i][j];
        ll res = 0;
        for(auto x : get_next(i, j, matrix))
        {
            ll i2 = x.first, j2 = x.second;
            res = max(res, dfs(vis, matrix, i2, j2));
        }
        return dp[i][j] = 1 + res;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        vvb vis(m, vb(n, false));
        ll res = 1;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(vis[i][j] == false) res = max(res, dfs(vis, matrix, i, j));
            }
        }
        return (int)res;
    }
};