class Solution {
public:
    int jump(vector<int>& nums) {
        vector<long long int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for(auto i = 0; i < nums.size()-1; i++)
        {
            for(auto j = 1; j <= nums[i]; j++){
                if(i + j < nums.size()) dp[i+j] = min(dp[i+j], dp[i] + 1);
            }
        }
        return dp[nums.size()-1];
    }
};