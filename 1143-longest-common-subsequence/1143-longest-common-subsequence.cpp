class Solution {
public:
#define INF (1e9+7)
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
//------------------------------------------------------------------------------------------------------------------
vvll dp_mem;
ll top_down(ll i, ll j, string &a, string &b)
{
    if(i == 0 or j == 0) return 0;
    if(dp_mem[i][j] != -1) return dp_mem[i][j];
    
    if(a[i-1] == b[j-1]) return dp_mem[i][j] = top_down(i-1, j-1, a, b) + 1;
    else return dp_mem[i][j] = max(top_down(i, j-1, a, b), top_down(i-1, j, a, b));
}
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
ll bottom_up(string a, string b)
{
    if(a.size() == 0 or b.size() == 0) return 0;
    vvll dp_tab(a.size()+1, vll (b.size()+1, 0));
    for(int i = 0; i < a.size(); i++) dp_tab[i][0] = 0;
    for(int j = 0; j < b.size(); j++)dp_tab[0][j] = 0;

    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            if(a[i-1] == b[j-1])
                dp_tab[i][j] = max(dp_tab[i-1][j-1] + 1, max(dp_tab[i-1][j], dp_tab[i][j-1]));
            else dp_tab[i][j] = max(dp_tab[i-1][j], dp_tab[i][j-1]);
        }
    }
    return dp_tab[a.size()][b.size()];
}
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
    int longestCommonSubsequence(string text1, string text2) {
        dp_mem.resize(text1.size()+1, vll (text2.size()+1, -1));
        return (int)top_down(text1.size(), text2.size(), text1, text2);
    }
};