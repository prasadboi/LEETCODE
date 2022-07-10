class Solution {
public:
    #define ll long long int
    #define INF (1e9 + 7)
    
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector<vi>
    #define vvll vector<vll>
    #define umap unordered_map
    #define uset unordered_set
    
    #define pub push_back
    #define pob pop_back
    #define F first()
    #define B back()    
    int minCost(vector<vector<int>>& costs) {
        // 0, 1, 2 : r, b, g
        // min cost to paint all the houses
        // no adjacent houses are same color
        // tot_cost[i][x] = min(tot_cost[i-1][x'], tot_cost[i-1][x'']) + costs[i][x]
        ll n = costs.size();
        
        if(n == 0) return 0;
        
        vvll dp(n, vll (3, INF));
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        for(auto i = 1; i < n; i++)
            for(auto j = 0; j < 3; j++)
                dp[i][j] = min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + costs[i][j];
        return (int)min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }
};