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

//     ------------------------------------------------------------------------------------------------------------- 
    void printMat(vvll mat)
    {
        for(auto i : mat){for(auto j : i) cout<<j<<" "; cout<<endl;}
    }
//     -------------------------------------------------------------------------------------------------------------
//     -------------------------------------------------------------------------------------------------------------
    vvll dp_mem;
    ll res;
    ll top_down(ll i, ll j, vvll &mat){
        if(i >= mat.size() or j >= mat[0].size()) return 0;
        if(dp_mem[i][j] > -1) return dp_mem[i][j];
        if(mat[i][j] == 0) return dp_mem[i][j] = 0;
        else
            dp_mem[i][j] = min(min(top_down(i-1, j, mat), top_down(i, j-1, mat)), top_down(i-1, j-1, mat)) + 1;
        return dp_mem[i][j];
    }
//     -------------------------------------------------------------------------------------------------------------
//     -------------------------------------------------------------------------------------------------------------
    ll bottom_up(ll m, ll n, vvll &mat)
    {
        for(auto i = 0; i < m; i++) {dp_mem[i][0] = mat[i][0];res = max(dp_mem[i][0], res);}
        for(auto j = 0; j < n; j++) {dp_mem[0][j] = mat[0][j];res = max(dp_mem[0][j], res);}

        for(auto i = 1; i < m; i++){
            for(auto j = 1; j < n; j++){
                if(mat[i][j] == 1) dp_mem[i][j] = min({dp_mem[i-1][j], dp_mem[i-1][j-1], dp_mem[i][j-1]}) + 1;
                else dp_mem[i][j] = 0;
                res = max(res, dp_mem[i][j]);
            }
        }
        return res;
    }
//     -------------------------------------------------------------------------------------------------------------
//     -------------------------------------------------------------------------------------------------------------
    int maximalSquare(vector<vector<char>>& matrix) {
        ll m = matrix.size();
        if(m == 0) return 0;
        ll n = matrix[0].size();
        
        res = 0;
        vvll mat(m, vll (n, 0));
        dp_mem.resize(m, vll(n, -1));
        
        for(auto i = 0; i < m; i++) for(auto j = 0; j < n; j++) mat[i][j] = matrix[i][j] - '0';
        
        // for(auto i = 0; i < m; i++) for(auto j = 0; j < n; j++) res = max(res, top_down(i, j, mat));
        res = max(res, bottom_up(m, n, mat));
        return (int) res*res;
    }
//     -------------------------------------------------------------------------------------------------------------
//     -------------------------------------------------------------------------------------------------------------
};