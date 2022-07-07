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

    
// unordered_map<ll, ll> dp;
// ll top_down(ll i, string s)
// {
//     // cout<<"string : "<<s.substr(0, i)<<endl;
//     if(i == 0) return 1;
//     if(i == 1 and s[0] > '0') return 1; else if(i == 1) return 0;

//     if(dp.find(i) != dp.end()) return dp[i];

//     ll res = 0;
//     string temp = s.substr(i-2, 2);
//     if(stoi(temp) <= 26 and stoi(temp) >= 10) res += top_down(i-2, s);
//     if(s[i-1] != '0')res += top_down(i-1, s); 
//     return dp[i] = res;
// }
ll bottom_up(string s)
{   
    if(s.size() == 0) return 1;
    vll dp(s.size() + 1, 0);
    dp[0] = 1;
    if(s[0] > '0') dp[1] = 1;
    for(auto i = 2; i <= s.size(); i++)
    {
        string temp = s.substr(i-2, 2);
        if(stoi(temp) >= 10 and stoi(temp) <= 26) dp[i] += dp[i-2];
        if(s[i-1] != '0') dp[i] += dp[i-1];
    }
    return dp[s.size()];
}    
    int numDecodings(string s) {
        // return (int) top_down(s.size(), s);
        return (int) bottom_up(s);
    }
};