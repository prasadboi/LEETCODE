class Solution {
public:
    #define ll long long int
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector<vi>
    #define vvll vector<vll>
    #define pll_ll pair<ll, ll>
    #define pi_i pair<int, int>
    #define umap unordered_map
    
    unordered_map<ll, ll> dp;
    ll top_down(int i, vi &nums)
    {
        if(i == -1) return 0;
        if(i == 0) return nums[0];
        // NOTE : dp.find(i) is a faster operation than dp[i] = 0;
        if(dp.find(i) != dp.end()) return dp[i];
        return dp[i] = max(top_down(i-1, nums), top_down(i-2, nums) + nums[i]);
    }
    
    ll bottom_up(vi &nums)
    {
        ll n = nums.size();
        vll dp(n, 0);
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(auto i = 2; i < n; i++)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        // return (int) top_down(nums.size()-1, nums);
        return (int)bottom_up(nums);
    }
};