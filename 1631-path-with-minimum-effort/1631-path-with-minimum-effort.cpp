class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define INF 1e9 + 7
    
    vector<pair<ll, ll>> get_nghbr(ll i, ll j, ll nx, ll ny)
    {
        vector<pair<ll, ll>> res;
        if(j > 0)res.push_back({i, j-1});
        if(i > 0) res.push_back({i-1, j});
        if(i < nx-1) res.push_back({i+1, j});
        if(j < ny-1) res.push_back({i, j+1});
        return res;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int nx = heights.size();
        int ny = heights[0].size();
        set<vector<ll>> q;
        vvll distance(nx, vector<ll> (ny, INF));
        q.insert({0, 0, 0});
        distance[0][0] = 0;
        while(!q.empty())
        {
            auto i = *(q.begin()); 
            ll u_d = i[0], u_x = i[1], u_y = i[2];
            // cout<<"at node : "<<u_x <<"-"<<u_y<<"at dist = "<<u_d<<endl;
            q.erase(q.begin());
            if(u_x == nx-1 and u_y == ny-1){
                // cout<<"---------------------------------\n";
                return u_d;
            }
            for(auto i : get_nghbr(u_x, u_y, nx, ny))
            {
                ll v_x = i.first, v_y = i.second;
                ll wt = abs(heights[u_x][u_y] - heights[v_x][v_y]);
                if(distance[v_x][v_y] > max(distance[u_x][u_y],wt))
                {
                    q.erase({distance[v_x][v_y], v_x, v_y});
                    distance[v_x][v_y] = max(distance[u_x][u_y],wt);
                    q.insert({distance[v_x][v_y], v_x, v_y});
                }
            }
            // for(auto i : distance){for(auto j : i) cout<<j<<" "; cout<<endl;}
        }
        return -1;
    }
};