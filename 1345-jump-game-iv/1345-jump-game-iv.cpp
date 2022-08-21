class Solution {
public:
    #define umap unordered_map
    #define ll long long int
    #define MAX ((ll)1e5)
    int minJumps(vector<int>& arr) {
        ll n = arr.size();
        umap<ll, vector<ll>> M;
        for(auto i = 0; i < n; i++){
            M[arr[i]].push_back(i);
        }
        
        ll ctr = 0;
        queue<ll> q; q.push(0);
        vector<ll> vis(n, 0);
        while(!q.empty())
        {
            ll k = q.size();
            while(k--)
            {
                ll u = q.front(); q.pop();
                if(u == n-1) return ctr;
                
                vector<ll> &V = M[arr[u]];
                if(u+1 < n)V.push_back(u+1);
                if(u-1 >= 0)V.push_back(u-1);
                for(auto v : V){
                    if(!vis[v]){
                        vis[v] = true; q.push(v);
                    }
                }
                V.clear();
            }
            ctr++;
        }
        return 0;
    }
};