class Solution {
public:
    #define vvll vector<vector<long long int>>
    #define ll long long int
    #define vb vector<bool>
    #define vll vector<ll>
    vvll graph;
    
    void dfs(ll src_x, ll src_y, vvll &visited, vvll &graph)
    {
        int n = graph.size();
        if(min(src_x, src_y) < 0 or max(src_x, src_y) >= n) return;
        if(visited[src_x][src_y] == 0 and graph[src_x][src_y] == 0)
        {
            visited[src_x][src_y] = 1;
            dfs(src_x + 1, src_y, visited, graph);
            dfs(src_x - 1, src_y, visited, graph);
            dfs(src_x, src_y + 1, visited, graph);
            dfs(src_x, src_y - 1, visited, graph);
        }

    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        graph.resize(3*n, vll(3*n, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '\\') graph[3*i][3*j] = 1, graph[3*i+1][3*j+1] = 1, graph[3*i + 2][3*j + 2] = 1;
                if(grid[i][j] == '/') graph[3*i+2][3*j] = 1, graph[3*i+1][3*j+1] = 1, graph[3*i][3*j + 2] = 1;
            }
        }
        // for(auto i : graph){for(auto j : i){cout<<j<<" ";}cout<<endl;}
        
        vvll visited(3*n, vll (3*n, 0));
        int ctr = 0;
        for(int i = 0; i < 3*n; i++)
        {
            for(int j = 0; j < 3*n; j++)
            {
                if(!visited[i][j] and graph[i][j] == 0){
                    dfs(i,j, visited, graph); ctr++;
                // for(auto i : visited){for(auto j : i){cout<<j<<" ";}cout<<endl;}
                }
            }
            
        }
        return ctr;
    }
};