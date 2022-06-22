class Solution {
public:
    #define vi vector<int>
    #define vb vector<bool>
    #define ll long long int
    #define vvi vector<vi>
    #define vll vector<ll>
    #define vvll vector<vll>
//     ----------------------------------------------------------------------------------------------------------------
    class DSU
    {
        vi parent, rank;
        public:
        
        DSU(int sz) : parent(sz), rank(sz){
            for(int i = 0; i < sz; i++) parent[i] = i, rank[i] = 1;
        }
        
        int FIND(int u)
        {
            if(parent[u] == u) return u;
            return parent[u] = FIND(parent[u]);
        }
        
        void UNION(int u, int v)
        {
            int U = FIND(u), V = FIND(v);
            if(U != V){
                if(rank[U] > rank[V])
                    parent[V] = U;
                else if(rank[V] > rank[U])
                    parent[U] = V;
                else{
                    parent[V] = U;
                    rank[U]++;
                }
            }
        }
        
        bool CONNECTED(int u, int v){
            return FIND(u) == FIND(v);
        }
    };    
//     ----------------------------------------------------------------------------------------------------------------

    
    static bool cmp(vi a, vi b)
    {
        return a[2] < b[2];
    }
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) 
    {
        // creating minimum spanning forest using kruskal's algorithm
        
        ll cost = 0;
        for(auto i : wells) cost += i;
        // cout<<cost<<"!\n";
        DSU dsu(n);
        sort(pipes.begin(), pipes.end(), cmp);
        for(auto i : pipes)
        {
            int u = i[0]-1, v = i[1] - 1, uv_wt = i[2];
            if(!dsu.CONNECTED(u, v))
            {
                // costU and costV are the cost of setting up wells in U and V
                int costU = wells[dsu.FIND(u)], costV = wells[dsu.FIND(v)];
                if(max(costU, costV) > uv_wt){
                    cost -= max(costU, costV);
                    cost += uv_wt;
                    if(costU > costV) wells[dsu.FIND(u)] = wells[dsu.FIND(v)];
                    else wells[dsu.FIND(v)] = wells[dsu.FIND(u)];
                    // cout<<"union-ing u = "<<u<<", costU = "<<costU<<"|| v = "<<v<<", costV = "<<costV<<" || uvwt = "<<uv_wt<<endl;
                    // cout<<"cost reduced to : "<<cost<<endl;
                    dsu.UNION(u, v);
                }
            }
        }
        return cost;
    }
};

















