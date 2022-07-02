class Solution {
public:
#define INF (1e9 + 7)
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
    
    
// -------------------------------------------------------------------------------------

umapll dp_mem; // using a hashap helps save a lot of bt when doing dp via memoization
ll top_down(ll i, vi arr)
{
    // BASE CASES:
    if(i == -1) return 0; // that there are no houses to rob
    if(i == 0) return arr[0]; // only one house under consideration
    else if(i == 1) return max(arr[0], arr[1]); // only 2 houses under consideration, we simply rob the richer house
    
    // memoization step
    if(dp_mem.find(i) != dp_mem.end()) return dp_mem[i];
    // recursive call and storing it in the hashmap dp_mem
    return dp_mem[i] = max(top_down(i-1, arr), arr[i] + top_down(i-2, arr));
}
// -------------------------------------------------------------------------------------
ll bottom_up(ll n, vi arr)
{
    vll dp_tab(n, 0);
    // BASE CASES:
    if(n == 0) return 0;
    dp_tab[0] = arr[0]; if(n == 1) return dp_tab[0]; 
    dp_tab[1] = max(arr[0], arr[1]);
    // Ordering is going from base cases to i = n-1 in increment fashion
    for(int i = 2; i < n; i++) dp_tab[i] = max(dp_tab[i-1], dp_tab[i-2] + arr[i]);
    return dp_tab[n-1];
}
// -------------------------------------------------------------------------------------   
    
int rob(vector<int>& nums) {
        return (int) bottom_up(nums.size(), nums);
        // return (int)top_down(nums.size()-1, nums);
    }
};