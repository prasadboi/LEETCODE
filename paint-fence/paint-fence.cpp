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
#define usetll unordered_set<ll>

#define pq priority_queue

unordered_map<ll, ll> dp;
ll top_down(ll n,  ll k)
{
    if(n == 0) return 0;
    if(n == 1) return k;
    if(n == 2) return k*k;
    if(dp.find(n) != dp.end()) return dp[n];
    return dp[n] = (k-1)*top_down(n-1, k) /*different color from previous*/ +  
                   (k-1)*top_down(n-2, k)/*same color as previous*/;
}

ll bottom_up(ll n, ll k)
{
    vll dp(n+1, 0);
    dp[0] = 0;
    if(n >= 1) dp[1] = k;
    if(n >= 2) dp[2] = k*k;
    for(auto i = 3; i <= n; i++) dp[i] = (k-1)*dp[i-1] + (k-1)*dp[i-2];
    return dp[n];
}
    
    int numWays(int n, int k) {
        // return (int) top_down((ll)n, (ll)k);
        return (int) bottom_up((ll)n, (ll)k);
    }
};