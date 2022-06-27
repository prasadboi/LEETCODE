class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define umapllvpll unordered_map<ll, vector<pair<ll, ll>>>
    #define umapllvll unordered_map<ll, vll>
    #define INF 1e9
    
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        umapllvll belongToRoute;
        for(int i = 0; i < routes.size(); i++)
            for(auto j : routes[i])
                belongToRoute[j].push_back(i);
        
        queue<pair<ll, ll>> q;
        unordered_set<ll> vis;
        q.push({source, 0}), vis.insert(source);

        while(!q.empty())
        {
            ll u = q.front().first, u_bus = q.front().second;
            q.pop();
            if(u == target) return u_bus;
            for(auto i : belongToRoute[u]){
                for(auto j : routes[i]){
                    if(vis.find(j) == vis.end()){
                        vis.insert(j);
                        q.push({j, u_bus + 1});
                    }
                }
                routes[i].clear();
            }
        }
        return -1;
    }
};