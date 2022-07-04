class Solution {
public:
#define ll long long
#define INF (1e9+7)
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
#define usetll unordered_set<ll>
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
umapll dp_mem;
ll top_down(int target, vi &denom)
{
    if(target == 0) return 0;
    if(dp_mem.find(target) != dp_mem.end()) return dp_mem[target];
    ll res = INF;
    for(auto coin : denom) if(target >= coin) res = min(res, top_down(target - coin, denom) + 1);
    return dp_mem[target] = res;
}
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
ll bottom_up_opti(int target, vi &denom)
{
    vll dp(target+1, INF);

    // base case:
    if(target and denom.size() == 0) return -1;
    dp[0] = 0;
    for(int i = 0; i <= target; i++){
        for(auto coin : denom) if(i >= coin) dp[i] = min(dp[i], 1 + dp[i-coin]);
    }
    if(dp[target] >= INF) return -1; else return dp[target];
}
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
    int coinChange(vector<int>& coins, int amount) {
        ll res = top_down(amount, coins);
        return ((res >= INF)?-1 : res);
        // return (int)bottom_up_opti(amount, coins);
    }
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
};