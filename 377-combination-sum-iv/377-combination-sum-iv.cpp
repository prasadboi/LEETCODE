class Solution {
public:
    
    #define ll unsigned long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    
    /*
    
    int combinationSum4(vector<int>& nums, int target) {
        ll n = nums.size();
        vvll dp(n+1, vll (target + 1, 0));
        // if target = 0; then dp[i][0] = 1
        // if i = 0 and target > 0 then dp[i][0] = 0;
        for(auto i = 0; i <= n; i++) dp[i][0] = 1;
        for(auto i = 1; i <= target; i++) dp[0][i] = 0;
        
        for(auto i =  1; i <= n; i++)
        {
            for(auto j = 1; j <= target; j++)
            {
                if(j - nums[i-1] >= 0) dp[i][j] = dp[i][j - nums[i-1]] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        // for(auto i : dp){for(auto j : i) cout<<j<<" "; cout<<endl;}
        return dp[n][target];
    }
    
    */
    int combinationSum4(vector<int>& nums, int target) {
        vll dp(target + 1, 0);
        dp[0] = 1;
        for(auto i = 1; i <= target; i++)
        {
            for(auto j = 0; j < nums.size(); j++)
            {
                if(i >= nums[j]) dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};