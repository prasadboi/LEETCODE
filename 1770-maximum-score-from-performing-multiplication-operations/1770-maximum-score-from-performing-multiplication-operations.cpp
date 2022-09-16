class Solution {
public:
    #define umap unordered_map
    #define uset unordered_set
    #define vi vector<int>
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    
    vector<vector<int>> dp;
    int solve(int i, int n, int j, vector<int> &nums, vector<int> &mul){
        if (j == mul.size()) return 0;
        if (dp[i][j] != INT_MIN) return dp[i][j];
        int left = solve(i + 1, n, j + 1, nums, mul) + (nums[i] * mul[j]);
        int right = solve(i, n, j + 1, nums, mul) + (nums[(n - 1) - (j - i)] * mul[j]);
        return dp[i][j] = max(left, right);
    }
    int maximumScore(vector<int>& nums, vector<int>& mul) {   
        int n = nums.size(), m = mul.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        return solve(0, n, 0, nums, mul);
    }
};