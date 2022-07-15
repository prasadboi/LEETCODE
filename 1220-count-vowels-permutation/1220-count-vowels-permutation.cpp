class Solution {
public:
    #define ll long long int
    #define umap unordered_map
    #define MOD ((ll)(1e9+7))
    #define vi vector<int>
    #define vll vector<ll>
    
    
    int n;
    umap<char, string> graph;
    umap<ll, umap<char, ll>> dp;
    ll dfs(int i, char vowel)
    {
        if(i == n) return 1;
        if(dp[i][vowel] != 0) return dp[i][vowel];
        ll ans = 0;
        for(auto v : graph[vowel]){
            ans = (ans + dfs(i+1, v))%MOD;
        }
        return dp[i][vowel] = ans;
    }
    int countVowelPermutation(int len) {
        n = len;
        graph['.'] = {'a', 'e', 'i', 'o', 'u'};
        graph['a'] = {'e'};
        graph['e'] = {'a', 'i'};
        graph['i'] = {'a', 'e', 'o', 'u'};
        graph['o'] = {'i', 'u'};
        graph['u'] = {'a'};
        return (int)dfs(0, '.');
    }
};