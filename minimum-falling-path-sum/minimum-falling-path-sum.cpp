class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp = matrix;
        for(int i = 1; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int res = INT_MAX;
                res = min(res, dp[i-1][j]);
                if(j > 0) res = min(res, dp[i-1][j-1]);
                if(j < n-1) res = min(res, dp[i-1][j+1]);
                dp[i][j] += res;
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) ans = min(ans, dp[dp.size()-1][i]);
        return ans;
    }
};