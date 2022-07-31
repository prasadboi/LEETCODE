class Solution {
public:
    
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define umap unordered_map
    #define vi vector<int>
    #define vvi vector<vi>
    umap<ll, umap<ll, ll>> dp;
    
    ll top_down(ll row, ll col, vvi &mat)
    {
        if(row == -1) return 0;
        if(col == -1 or col == mat[0].size()) return INT_MAX;
        if(dp.find(row) != dp.end() and dp[row].find(col) != dp[row].end()) return dp[row][col];
        ll res = mat[row][col];
        if(row > 0) res += min({top_down(row-1, col, mat), top_down(row-1, col - 1, mat), top_down(row-1, col+1, mat)});
        return dp[row][col] = res;
    }
    
    int minFallingPathSum(vector<vector<int>>& mat) {
        ll res = INT_MAX;
        for(auto i = 0; i < mat[0].size(); i++)
            res = min(res, top_down(mat.size()-1, i, mat));
        return res;
    }
};