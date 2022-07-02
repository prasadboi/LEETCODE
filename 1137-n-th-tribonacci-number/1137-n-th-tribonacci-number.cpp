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

// SOLUTION:
// T[i+3] = T[i] + T[i+1] + T[i+3]  -> recurrence gisven
// base situations : T[0] = 0, T[1] = 1, T[2] = 1
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
umapll dp_mem;
ll top_down(ll n){
    if(n == 0) return 0;
    if(n == 1 or n == 2) return 1;
    if(dp_mem.find(n) != dp_mem.end()) return dp_mem[n];
    return dp_mem[n] = top_down(n-1) + top_down(n-2) + top_down(n-3);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
ll bottom_up(ll n){
    vll dp_tab;
    if(n > 2) dp_tab.resize(n+1, 0); else dp_tab.resize(3, 0);
    dp_tab[0] = 0, dp_tab[1] = dp_tab[2] = 1;
    for(auto i = 3; i <= n; i++)
        dp_tab[i] = dp_tab[i-1] + dp_tab[i-2] + dp_tab[i-3];
    return dp_tab[n];
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

    int tribonacci(int n) {
        // return top_down((ll)n);
        return bottom_up((ll)n);
    }
};