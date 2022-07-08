class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++){if(grid[i][0]) break; dp[i][0] = 1;}
        for(int j = 0; j < n; j++){if(grid[0][j]) break; dp[0][j] = 1;}
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++)
            {
                if(grid[i][j] == 1){continue;}
                int res = 0;
                if(dp[i-1][j]) res += dp[i-1][j];
                if(dp[i][j-1]) res += dp[i][j-1];
                dp[i][j] = res;
            }
        }
        for(auto i : dp) {for(auto j : i) cout<<j<<" "; cout<<endl;}
        return dp[m-1][n-1];
    }
};