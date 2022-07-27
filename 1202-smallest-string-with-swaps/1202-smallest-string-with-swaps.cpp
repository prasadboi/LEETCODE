class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define umap unordered_map
    #define vb vector<bool>
    
    umap<ll, vll> graph; umap<ll, ll> vis;
    void dfs(ll u, string &component, vll &comp_indices, string &s){
        vis[u] = 1;
        comp_indices.push_back(u);
        component.push_back(s[u]);
        for(auto v : graph[u])
            if(vis[v] == 0) dfs(v, component, comp_indices, s);
    }
    
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // there exists only one lexicographically smallest ordering for a connected set of pairs
        for(auto i : pairs){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        string res = s;
        for(auto i : graph)
        {
            ll u = i.first;
            string component;
            vll comp_indices;
            if(vis[u] == 0){
                dfs(u, component, comp_indices, s);
                sort(component.begin(), component.end());
                sort(comp_indices.begin(), comp_indices.end());
                for(auto j = 0; j < component.size(); j++)
                    res[comp_indices[j]] = component[j];
            }
        }
        return res;
    }
};