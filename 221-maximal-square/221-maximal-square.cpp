class Solution {
public:
#define ll long long
#define INF (1e9 + 7)
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vpll vector<pair<ll, ll>>
#define vvpll vector<vpll>
#define vstr vector<string>
#define vchr vector<char>
#define vb vector<bool>
#define vvb vector<vb>

#define pii pair<int, int>
#define pll pair<ll, ll>

#define umapii unordered_map<int, int>
#define umapll unordered_map<ll, ll>
#define umapis unordered_map<int, string>
#define umapchr unordered_map<char, int>
#define umapss unordered_map<string, string>

#define mapii map<int, int>
#define mapll map<ll, ll>
#define mapsi map<string, int>
#define mapsll map<string, ll>
#define mapci map<char, int>
#define mapcl map<char, ll>
#define mapss map<string, string>

#define usetii unordered_set<int>
#define usetll unordered_set<ll>

#define umap unordered_map
    
    
    
    vvll mat;
    ll ans = 0;
    umap<ll, umap<ll, ll>> dp;
    ll top_down(ll i, ll j)
    {
        if(i == 0 or j == 0) return mat[i][j];
        if(dp[i][j] != 0) return dp[i][j];
        ll res = 0;
        if(mat[i][j])
            res = 1 + min({top_down(i-1, j-1), top_down(i, j-1), top_down(i-1, j)});
        else return dp[i][j] = 0;
        // cout<<"i = "<<i<<", j = "<<j<<", res = "<<res<<endl;
        return dp[i][j] = res;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        mat.resize(n, vll (m, 0));
        for(auto i = 0; i < n; i++)
            for(auto j = 0; j < m; j++)
                mat[i][j] = matrix[i][j] - '0', ans = max(ans, mat[i][j]);
        
        for(auto i = 0; i < n; i++)
            for(auto j = 0; j < m; j++)
                ans = max(ans, top_down(i, j));
        return ans*ans;
    }
};