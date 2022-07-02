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
class Solution {
public:
//---------------------------------------------------------------------------------------
umapll cost_dp_mem;
ll top_down(ll i, vi arr){
    if(i == 0) return arr[0];
    if(i == 1) return arr[1];
    if(cost_dp_mem.find(i) != cost_dp_mem.end()) return cost_dp_mem[i];
    return cost_dp_mem[i] = min(top_down(i-1, arr) + arr[i], top_down(i-2, arr) + arr[i]);
}
//---------------------------------------------------------------------------------------

    int minCostClimbingStairs(vector<int>& cost) {
        return (int) min(top_down(cost.size()-1, cost), top_down(cost.size()-2, cost));
    }
};