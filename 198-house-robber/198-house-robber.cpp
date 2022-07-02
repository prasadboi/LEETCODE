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
    int rob(vector<int>& nums) {
        return (int)top_down(nums.size()-1, nums);
    }
};