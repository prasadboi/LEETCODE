
    

class Solution {
public:
    #define ll long long int
    #define INF 1e9
    #define pll pair<ll, ll>
    #define pii pair<int, int>
    #define vi vector<int>
    #define vpii vector<pii>
    #define vll vector<ll>
    #define vpll vector<pair<ll, ll>>
    #define vvpii vector<vpii>
    #define vvpll vector<vpll>
    #define vvll vector<vll>
    #define vvi vector<vector<int>>
    
    
    vpll get_nghbrs(pll u, vvi &maze)
    {
        vpll res;
        ll x = u.first, y = u.second;
        ll nx = maze.size(), ny = maze[0].size();
        int t = x;
        while(t > -1 and maze[t][y] != 1) t--; res.push_back({t+1, y});
        t = x;
        while(t < nx and maze[t][y] == 0) t++; res.push_back({t-1, y});
        t = y;
        while(t > -1 and maze[x][t] == 0) t--; res.push_back({x, t+1});
        t = y;
        while(t < ny and maze[x][t] == 0) t++; res.push_back({x, t-1});
        return res;
    }
    
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) 
    {
        if(maze.size() == 0) return 0;
        queue<pll> q;
        ll nx = maze.size(), ny = maze[0].size();
        vvll dist(nx, vll (ny, -1));
        
        dist[start[0]][start[1]] = 0;
        q.push({start[0], start[1]});
        while(!q.empty())
        {
            ll ux = q.front().first, uy = q.front().second; 
            q.pop();
            for(auto v : get_nghbrs({ux, uy}, maze))
            {
                ll vx = v.first, vy = v.second;
                if(dist[vx][vy] == -1){
                    q.push({vx, vy});
                    dist[vx][vy] = dist[ux][uy] + abs(vx - ux) + abs(vy - uy);
                }
                else if(dist[ux][uy] + abs(vx - ux) + abs(vy - uy) < dist[vx][vy]){
                    q.push({vx, vy});
                    dist[vx][vy] = dist[ux][uy] + abs(vx - ux) + abs(vy - uy);
                }
            }
        }
        return dist[dest[0]][dest[1]];
    }
};