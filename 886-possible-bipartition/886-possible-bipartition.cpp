class Solution {
public:
    #define vi vector<int>
    #define vvii vector<vi>
    #define ll long long int
    #define vb vector<bool>
    
    vi state;
    vvii graph;
    
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
    
    
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        graph.resize(n);
        for(auto i : dislikes){
            graph[i[0]-1].push_back(i[1]-1);
            graph[i[1] - 1].push_back(i[0] - 1);
        }
        bool flag = true;
        state.resize(n, 0);
        for(int i = 0; i < n; i++){
            if(state[i] == 0) flag = flag and dfs(i, 0, graph);
        }
        return flag;
    }
};