class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define vb vector<bool>
    #define vi vector<int>
    #define vvi vector<vi>
    
    int countSquares(vector<vector<int>>& mat) {
        ll n = mat.size(), m = mat[0].size(), res = 0;
        vvll dp(n, vll(m, 0));
        for(auto i = 0; i < n; i++) dp[i][0] = mat[i][0], res += mat[i][0];
        for(auto j = 1; j < m; j++) dp[0][j] = mat[0][j], res += mat[0][j];
        for(auto i = 1; i < n; i++)
        {
            for(auto j = 1; j < m; j++)
            {
                if(mat[i][j])
                    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}), res += dp[i][j];
                else dp[i][j] = 0;
                // cout<<"i = "<<i<<", j = "<<j<<", dp = "<<dp[i][j]<<endl;
            }
        }
        return res;
    }
};