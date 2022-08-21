class Solution {
public:
    // sol using DP : O(n^2) time, O(n) space
    // 
    // int jump(vector<int>& nums) {
    //     vector<long long int> dp(nums.size(), INT_MAX);
    //     dp[0] = 0;
    //     for(auto i = 0; i < nums.size()-1; i++)
    //     {
    //         for(auto j = 0; j <= nums[i]; j++){
    //             if(i + j < nums.size()) dp[i+j] = min(dp[i+j], dp[i] + 1);
    //         }
    //     }
    //     return dp[nums.size()-1];
    // }
    
    int jump(vector<int>& nums) {
        int maxReachable = 0, i = 0, lastPos = 0, ctr = 0;
        for(; i < nums.size()-1; i++)
        {
            maxReachable = max(maxReachable, nums[i] + i);
            if(i == lastPos){
                lastPos = max(lastPos, maxReachable);
                ctr++;
            }
        }
        return ctr;
    }
};