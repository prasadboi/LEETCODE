class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define vb vector<bool>
    #define vvb vector<vb>
    #define umap unordered_map
    #define uset unordered_set
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vvll adj(n, (vll (n, 0)));
        vll degree(n, 0);
        
        for(auto i : roads){
            adj[i[0]][i[1]]++;
            adj[i[1]][i[0]]++;
            degree[i[1]]++, degree[i[0]]++;
        }
        ll res = 0;
        for(auto i = 0; i < n; i++)
            for(auto j = i+1; j < n; j++)
                res = max(res, degree[i] + degree[j] - adj[i][j]);
        return (int)res;
        
    }
};