class Solution {
public:
#define ll long long

#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vpll vector<pair<ll, ll>>
#define vvpll vector<vpll>
#define vstr vector<string>
#define vchr vector<char>
#define vb vector<bool>
#define vvb vector<vb>

#define pii pair<int, int>
#define pll pair<ll, ll>

#define umapii unordered_map<int, int>
#define umapll unordered_map<ll, ll>
#define umapis unordered_map<int, string>
#define umapchr unordered_map<char, int>
#define umapss unordered_map<string, string>

#define mapii map<int, int>
#define mapll map<ll, ll>
#define mapsi map<string, int>
#define mapsll map<string, ll>
#define mapci map<char, int>
#define mapcl map<char, ll>
#define mapss map<string, string>

#define usetii unordered_set<int>

unordered_map<ll, unordered_map<ll, ll>> dp;
ll top_down(ll amount, ll i, vi coins)
{
    if(amount == 0) return 1;
    if(i == 0) return 0;
    
    if(dp.find(i) != dp.end() and dp[i].find(amount) != dp[i].end()) return dp[i][amount];
    
    ll res = 0;
    ll n = coins.size();
    if(amount >= coins[i-1]) res += top_down(amount - coins[i-1], i, coins);
    res += top_down(amount, i-1, coins);
    return dp[i][amount] = res;
}
    
    
ll bottom_up(ll amount, vi coins)
{
    ll n = coins.size();
    vvll dp(n+1, vll (amount+1, 0));

    for(auto j = 0; j <= amount; j++) dp[0][j] = 0;
    for(auto i = 0; i <= n; i++) dp[i][0] = 1;

    for(auto i = 1; i <= n; i++){
        for(auto j = 1; j <= amount; j++){
            if(j >= coins[i-1]) dp[i][j] += dp[i][j-coins[i-1]];
            dp[i][j] += dp[i-1][j];
        }
    }
    return dp[n][amount];
}    
    int change(int amount, vector<int>& coins) {
        return (int) bottom_up(amount, coins);
    }
};