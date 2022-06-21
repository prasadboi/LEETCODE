class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vb vector<bool>
    #define vvll vector<vll>
    
    int largestPathValue(string color, vector<vector<int>>& edges) 
    {
        // construct graph
        ll n = color.size();
        if(n == 0) return 0;
        if(edges.size() == 0) return 1;
        vvll graph(n);
        vll indegree(n, 0);
        
        for(auto i : edges){
            graph[i[0]].push_back(i[1]); 
            indegree[i[1]]++;
        }
        
        vvll dp(n, vll (26, 0));
        
        // running bfs while maintaining color freq at every node
        queue<ll> q;
        ll res = -1;
        
        ll src = 0, ctr = 0;
        for(int i = 0; i < n; i++) if(indegree[i] == 0){q.push(i); dp[i][color[i] - 'a'] = 1;}
        // for(auto i : indegree) cout<<i<<" "; cout<<endl;
        // for(auto i : dp[src]) cout<<i<<" "; cout<<endl;
        while(!q.empty())
        {
            ll u = q.front(); q.pop();
            res = max((ll)res, *max_element(begin(dp[u]), end(dp[u])));
            for(auto v : graph[u])
            {
                for(int i = 0; i < 26; i++)
                    dp[v][i] = max(dp[v][i], dp[u][i]);
                dp[v][color[v] - 'a'] = max(dp[v][color[v] - 'a'], dp[u][color[v] - 'a'] + 1); 

                if(--indegree[v] == 0)
                    q.push(v);
            }
            ctr++;
        }
        // cout<<"-----------------------------------\n";
        if(ctr != n) return -1;
        else return res;
    }
    //------------------------------------------------------------
};



















