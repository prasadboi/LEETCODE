class Solution {
public:
    #define vb vector<bool>
    #define vi vector<int>
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vector<ll>>
    
    bool helper(ll src, ll dest, vvll &graph)
    {
        queue<ll> q;
        q.push(src);
        vb vis(graph.size(), false);
        while(!q.empty())
        {
            ll v = q.front();
            q.pop();
            for(auto u : graph[v])
            {
                if(!vis[u]){
                    vis[u] = true;
                    q.push(u);
                    if(u == dest) {return true;}
                }
            }
        }
        return false;
    }
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int t = queries.size();
//         making graph
        int n = numCourses;
        vvll graph(n);
        for(auto i : prerequisites)
        {
            graph[i[0]].push_back(i[1]);
        }
        
        cout<<t<<endl;
        vb res;
        for(auto i : queries)
        {
            res.push_back(helper(i[0], i[1], graph));
        }
        return res;
    }
};