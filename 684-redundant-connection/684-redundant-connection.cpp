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
        // NOTE : pair<x, y> can be used as a key only in map, set etc. and not in their unordered counterparts
        map<pair<int, int>, int> edgeNum;
        
        graph.resize(n); 
        for(int i = 0; i < n; i++)
        {
            // store all the edges with their relative ordering information
            edgeNum[{edges[i][0]-1, edges[i][1]-1}] = i; 
            
            // build undirected graph
            graph[edges[i][0] - 1].push_back(edges[i][1]-1);
            graph[edges[i][1] - 1].push_back(edges[i][0]-1);
        }
        
        // standard cycle detection and identification in a undirected graph
        vi cycle = find_cycle();
        vi res(2, -1);
        int order = INT_MIN;
        
        // here on forth it is just searching that edge in the map such that 
        // the edge that in the cycle which was entered last in the output is found
        for(int i = 0; i < cycle.size()-1; i++)
        {
            int temp;
            if(edgeNum.find({cycle[i], cycle[i+1]}) != edgeNum.end()){
                temp = edgeNum[{cycle[i], cycle[i+1]}];
                if(order < temp){
                    order = temp;
                    res[0] = cycle[i], res[1] = cycle[i+1];
                }
            }
            else{
                temp = edgeNum[{cycle[i+1], cycle[i]}];
                if(order < temp){
                    order = temp;
                    res[0] = cycle[i+1], res[1] = cycle[i];
                }
            }
        }
        res[0]++, res[1]++;
        return res;
    }
};