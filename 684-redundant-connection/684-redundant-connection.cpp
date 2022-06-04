class Solution {
public:
    
    #define vvii vector<vector<int>> 
    #define vi vector<int>
    #define ll long long int
    
    vvii graph;
    vi color, parent;
    int n, cycle_start, cycle_end;
    
    bool DFS(int v, int par)
    {
        color[v] = 1;
        for(auto u : graph[v])
        {
            if(u == par) continue;
            if(color[u] == 1){
                cycle_start = u, cycle_end = v; return true;
            }
            parent[u] = v;
            if(DFS(u, parent[u])) return true;
        }
        return false;
    }
    
    vector<int> find_cycle()
    {
        color.resize(n, 0); parent.resize(n, -1);
        cycle_start = -1, cycle_end = -1;
        
        for(int v = 0; v < n; v++)
            if(color[v] == 0 and DFS(v, parent[v])) break;
        
        vi cycle;
        if(cycle_start == -1) return cycle;
        else
        {
            cycle.push_back(cycle_start);
            for(int v = cycle_end; v != cycle_start; v = parent[v])
                cycle.push_back(v);
            cycle.push_back(cycle_start);
            reverse(cycle.begin(), cycle.end());
            return cycle;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        n = edges.size();
        map<pair<int, int>, int> edgeNum;
        
        graph.resize(n); 
        for(int i = 0; i < n; i++)
        {
            edgeNum[{edges[i][0]-1, edges[i][1]-1}] = i;
            
            graph[edges[i][0] - 1].push_back(edges[i][1]-1);
            graph[edges[i][1] - 1].push_back(edges[i][0]-1);
        }
        
        vi cycle = find_cycle();
        vi res(2, -1);
        // for(auto i : cycle) cout<<i<<" ";
        // cout<<endl;
        int order = INT_MIN;
        
        // here on forth it is just searching that edge in the map
        for(int i = 0; i < cycle.size()-1; i++)
        {
            int temp;
            if(edgeNum.find({cycle[i], cycle[i+1]}) != edgeNum.end()){
                temp = edgeNum[{cycle[i], cycle[i+1]}];
                if(order < temp){
                    order = temp;
                    // cout<<"order = "<<order<<endl;
                    res[0] = cycle[i], res[1] = cycle[i+1];
                }
            }
            else{
                temp = edgeNum[{cycle[i+1], cycle[i]}];
                if(order < temp){
                    order = temp;
                    // cout<<"order = "<<order<<endl; 
                    res[0] = cycle[i+1], res[1] = cycle[i];
                }
            }
        }
        res[0]++, res[1]++;
        return res;
    }
};