class Solution {
public:
    #define vb vector<bool>
    #define vi vector<int>
    #define vvii vector<vector<int>> 
    #define ll long long int
    
    vi state ; // an array taht maintains coloring and state (vis or not vis) for every node 
    
    bool dfs(int src, int pns, vvii &graph) // pns = previous node state
    {
        // cout<<"node = "<<src<<", curr state = "<<state[src]<<", pns = "<<pns<<endl;
        if(state[src] != 0 and state[src] == pns) return false;
        else if(state[src] == 0){
            if(pns == 1) state[src] = 2;
            else state[src] = 1;
        }
        
        bool flag = true;
        
        for(auto i : graph[src])
        {
            if(state[i] != 0 and state[i] == state[src]) return false;
            else if(state[i] == 0)
            {
                flag = flag and dfs(i, state[src], graph);
            }
        }
        return flag;
    }
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        state.resize(n,0);
        bool flag = true;
        for(int i = 0; i < n; i++)
            if(state[i] == 0) flag = flag and dfs(i, 0, graph);
        return flag;
    }
};