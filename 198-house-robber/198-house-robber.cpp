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
        if(dp.find(i) != dp.end()) return dp[i];
        return dp[i] = max(top_down(i-1, nums), top_down(i-2, nums) + nums[i]);
    }
    int rob(vector<int>& nums) {
        return (int) top_down(nums.size()-1, nums);
    }
};