class Solution {
public:
#define ll long long
#define INF (1e9 + 7)
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
// define dp[i] : the maximum number of points collected by considering all numbers in the array in the range 0 - i (inclusive)
// ans is dp[n] where n = maximum number in the array given

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
umapll dp_mem, freq;
ll top_down(ll n, vi arr, umapll freq){
    // BASE CASES:
    if(n == 0) return 0;
    if(n == 1) return freq[1]*1;
    // MEMO
    if(dp_mem.find(n) != dp_mem.end()) return dp_mem[n];
    if(freq.find(n) != freq.end() and freq[n] > 0)
        dp_mem[n] = max(top_down(n-1, arr, freq), top_down(n-2, arr, freq) + n*freq[n]);
    else dp_mem[n] = top_down(n-1,arr, freq);
    
    return dp_mem[n];
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
ll bottom_up(ll n, vi arr, umapll freq)
{
    if(n == 0) return 0;
    vll dp_tab(n+1, 0);
    if(freq.find(1) != freq.end())dp_tab[1] = freq[1]*1;
    for(int i = 2; i <= n; i++){
        if(freq.find(i) != freq.end()) dp_tab[i] = max(dp_tab[i-1], dp_tab[i-2] + freq[i]*i);
        else dp_tab[i] = dp_tab[i-1];
    }
    return dp_tab[n];
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    int deleteAndEarn(vector<int>& nums) {
        freq.clear();

        ll maxi = INT_MIN;
        for(auto i : nums) {freq[i]++; maxi = max(maxi, (ll)i);}
        // return (int)top_down(maxi, nums, freq);
        // need to make more than usual optimizations to do recursive dp (top-down ie).
        
        return (int) bottom_up(maxi, nums, freq);
    }
};