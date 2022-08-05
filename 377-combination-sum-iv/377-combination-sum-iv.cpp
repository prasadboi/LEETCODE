class Solution {
public:
    
    #define ll unsigned long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    
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