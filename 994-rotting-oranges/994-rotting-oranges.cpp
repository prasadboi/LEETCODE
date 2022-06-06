class Solution {
public:
    #define vvi vector<vector<int>>
    #define vvpii vector<vector<pair<int, int>>>
    #define vi vector<int>
    #define vvb vector<vector<bool>>
    
    vector<pair<int, int>> nextNode(int x, int y, int nx, int ny)
    {
        vector<pair<int , int>>  next;
        if(y > 0)
        {
            next.push_back({x, y-1});
        }
        if(x > 0) next.push_back({x-1, y});
        if(x < nx-1) next.push_back({x+1, y});
        if(y < ny-1)
        {
            next.push_back({x, y+1});
        }
        return next;
    }
    
    int orangesRotting(vector<vector<int>>& grid) 
    {
        // run bfs on every connected component while maintaining the maximum time elapsed
        int nx = grid.size(), ny = grid[0].size();
        vvb vis(nx, vector<bool> (ny, false));
        vvpii parent(nx, vector<pair<int, int>> (ny, pair<int, int> ({-1, -1})));
        vvi dist(nx, vi (ny, INT_MAX-1));
        int result = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < nx; i++)
        {
            for(int j = 0; j < ny; j++)
            {
                if(grid[i][j] != 2) continue;
                vis[i][j] = true;
                q.push({i, j});
                dist[i][j] = 0;
                parent[i][j] = {-1, -1};
 
            }
        }
        
        for(int i = 0; i < nx; i++)
        {
            for(int j = 0; j < ny; j++)
            {
                while(!q.empty())
                {
                    pair<int, int> curr = q.front(); q.pop();
                    if(grid[curr.first][curr.second] == 1) continue;
                    result = max(result, dist[curr.first][curr.second]);
                    for(auto next : nextNode(curr.first, curr.second, nx, ny))
                    {
                        if(!vis[next.first][next.second] and grid[next.first][next.second] == 1)
                        {
                            // cout<<"killing orange "<<next.first<<"-"<<next.second<<endl;
                            vis[next.first][next.second] = true;
                            grid[next.first][next.second] = 2;
                            dist[next.first][next.second] = 1 + dist[curr.first][curr.second];
                            parent[next.first][next.second] = curr;
                            q.push({next.first, next.second});
                        }
                    }
                }
            }
        }
        for(auto i : grid)
        {
            for(auto j : i) if(j == 1) return -1;
        }
        return result;
    }
};



















