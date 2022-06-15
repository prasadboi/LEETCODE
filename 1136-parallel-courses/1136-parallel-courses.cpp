class Solution {
public:
    #define vll vector<long long int>
    #define vvll vector<vll>
    #define ll long long int
    
    
    
    int minimumSemesters(int n, vector<vector<int>>& relations) 
    {
        vvll graph(n);
        vll indegree(n,0), outdegree(n, 0);
        for(auto i : relations){
            graph[i[0]-1].push_back(i[1]-1);
            indegree[i[1]-1]++;
            outdegree[i[0]-1]++;
        }
        
        queue<ll> q;
        int sem = 0;
        int ctr = 0;
        
        for(int i = 0; i < n; i++) if(indegree[i] == 0) q.push(i);
        while(!q.empty())
        {
            int k = q.size();
            // cout<<"k = "<<k<<", sem = "<<sem<<endl;
            for(int i = 0; i < k; i++)
            {
                ll u = q.front(); q.pop();
                for(auto v : graph[u])
                    if(--indegree[v] == 0) q.push(v);
                ctr++;
            }
            sem++;
        }
        if(ctr == n) return sem; else return -1;
    }
};