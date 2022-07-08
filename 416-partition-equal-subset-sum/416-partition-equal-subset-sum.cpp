class Solution {
public:
    #define vi vector<int>
    #define ll long long int
    #define vll vector<ll>
    #define vvi vector<vi>
    #define vvll vector<vll>
    #define INF (1e9 + 7)
    #define vb vector<bool>
    #define vvb vector<vector<bool>>
    
    bool canPartition(vector<int>& nums) 
    {
        ll sum = 0;
        for(auto i : nums) sum += i;
        ll n = nums.size();
        vvb dp(n+1, vb ((sum/2) + 1, false));
        if(sum%2) return false;
        for(auto j = 0; j <= sum/2; j++) dp[0][j] = false;
        for(auto i = 0; i <= n; i++) dp[i][0] = true;
        for(auto i = 1; i <= n; i++)
        {
            for(auto j = 1; j <= sum/2; j++)
            {
                if(j >= nums[i-1]) dp[i][j] = dp[i][j] or dp[i-1][j - nums[i-1]];
                dp[i][j] = dp[i][j] or dp[i-1][j];
            }
        }
        return dp[n][sum/2];
    }
};