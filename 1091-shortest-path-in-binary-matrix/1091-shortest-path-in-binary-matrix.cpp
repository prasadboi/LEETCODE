class Solution {
public:
    // returns vector containing coords of possible next moves
    vector<pair<int, int>> move(int x, int y, int n)
    {
        vector<pair<int, int>> next;
        if(y > 0 and x > 0) next.push_back({x-1, y-1});
        if(y > 0 and x < n-1) next.push_back({x+1, y-1});
        if(y > 0) next.push_back({x, y-1});
        
        if(x > 0) next.push_back({x-1, y});
        if(x < n-1) next.push_back({x+1, y});
        
        if(y < n-1 and x > 0) next.push_back({x-1, y+1});
        if(y < n-1 and x < n-1) next.push_back({x+1, y+1});
        if(y < n-1) next.push_back({x, y+1});
        return next;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int> (n, 0)), dist(n, vector<int> (n, INT_MAX));
        vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>> (n));
        queue<pair<int, int>> q;
        
        
        if(grid[0][0] == 0){
            q.push({0, 0});
            vis[0][0] = 1;
            dist[0][0] = 0;
            parent[0][0] = {-1, -1};
        }
        
        while(!q.empty())
        {
            pair<int, int> coord = q.front(); q.pop();
            // cout<<"at node : "<<coord.first<<" - "<<coord.second<<endl;
            // cout<<"is at dist : "<<dist[coord.first][coord.second]<<endl<<endl;
            for(auto i : move(coord.first, coord.second, n))
            {
                if(vis[i.first][i.second] == 0 and grid[i.first][i.second] == 0){
                    vis[i.first][i.second] = 1;
                    parent[i.first][i.second] = coord;
                    dist[i.first][i.second] = 1 + dist[coord.first][coord.second];
                    q.push(i);
                }
            }
        }
        
       if(dist[n-1][n-1] < INT_MAX) return dist[n-1][n-1] + 1; else return -1; 
    }
};























