class Solution {
public:
    #define vvpii vector<vector<pair<int, int>>>
    #define vi vector<int>
    #define vb vector<bool>
    
    vvpii graph;
    vb visited;
    vi entry_time;
    vi exit_time;
    
    void dfs(int src, int time)
    {
        entry_time[src] = exit_time[src] = time;
        visited[src] = true;
        // cout<<"marked src = "<<src<<" as true";
        for(auto i : graph[src])
        {
            int node = i.first;
            int delay = i.second;
            if(!visited[node]){
                dfs(node, time + delay);
            }
            else if(time + delay < entry_time[node]){
                dfs(node, time + delay);
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        graph.resize(n);
        visited.resize(n, false);
        entry_time.resize(n, 0);
        exit_time.resize(n, 0);
        
        for(auto i : times)
        {
            graph[i[0]-1].push_back({i[1]-1, i[2]});
        }
        dfs(k-1, 0);        
        for(auto i : visited) if(!i) return -1; 
        int max_exit = 0;
        for(auto i : exit_time) max_exit = max(max_exit, i);
        return max_exit;
    }
};