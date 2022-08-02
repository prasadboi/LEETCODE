
// class Solution {
// public:
//     #define ll long long int
//     #define INF (1e9 + 7)
    
//     #define vi vector<int>
//     #define vll vector<ll>
//     #define vvi vector<vi>
//     #define vvll vector<vll>
//     #define umap unordered_map
//     #define uset unordered_set
    
//     #define pub push_back
//     #define pob pop_back
//     #define F first()
//     #define B back()
    
//     umap<ll, umap<ll, ll>> dp;
//     // states : 0 indexed day; currently holding or not holding stock
//     ll top_down(ll day, bool hold_stock, vi &prices, ll fee)
//     {
//         if(day >= prices.size()) return 0;
//         if(dp[day][hold_stock] != 0) return dp[day][hold_stock];
        
//         if(hold_stock == 1) // ability to sell today (i have stocks in my hand)
//             return dp[day][hold_stock] = max(
//                                             /*hold on*/top_down(day+1, 1, prices, fee),
//                                             /*sell today*/ top_down(day + 1, 0, prices, fee) + prices[day] - fee
//                                             );
        
//         else // ability to buy today (my portfolio is empty right now)
//             return dp[day][hold_stock] = max(
//                                             /*buy today*/top_down(day+1, 0, prices, fee),
//                                             /*take lite*/top_down(day+1, 1, prices, fee) - prices[day]
//                                             );
//     }
    
//     ll bottom_up(vi &prices, ll fee)
//     {
//         ll n = prices.size();
//         if(n == 0) return 0;
//         vvll dp(n+1, vll (2, 0));
//         for(auto i = n-1; i >= 0; i--)
//         {
//             dp[i][0] = max(dp[i+1][0], dp[i+1][1] - prices[i]);
//             dp[i][1] = max(dp[i+1][1], dp[i+1][0] + prices[i] - fee);
//         }
//         return dp[0][0];
//     }
//     int maxProfit(vector<int>& prices, int fee) {
//         // return (int)top_down(0, 0, prices, fee);
//         return (int) bottom_up(prices, fee);
//     }
// };
// 


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
    
    int maxProfit(vector<int>& prices, int fee) {
        ll n = prices.size();
        vvll dp(n+1, vll(2, 0));
        dp[0][0] = 0;
        dp[0][1] = INT_MIN;
        for(auto i = 1; i <= n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1] - fee); // had stock yesterday , sold today
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i-1]); // didnt have stock yesterday, bought today
        }
        return dp[n][0];
    }
};