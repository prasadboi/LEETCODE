class Solution {
public:
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vpll vector<pair<ll, ll>>
#define vvpll vector<vpll>
#define vstr vector<string>
#define vchr vector<char>
#define vb vector<bool>
#define vvb vector<vb>

#define pii pair<int, int>
#define pll pair<ll, ll>

#define umapii unordered_map<int, int>
#define umapll unordered_map<ll, ll>
#define umapis unordered_map<int, string>
#define umapchr unordered_map<char, int>
#define umapss unordered_map<string, string>

#define mapii map<int, int>
#define mapll map<ll, ll>
#define mapsi map<string, int>
#define mapsll map<string, ll>
#define mapci map<char, int>
#define mapcl map<char, ll>
#define mapss map<string, string>

#define usetii unordered_set<int>
#define usetll unordered_set<ll>

#define pq priority_queue
    
class DSU
{
private :
    vll rank, parent;
    ll conn_comp;
public :
    DSU(int size) : rank(size), parent(size)
    {
        conn_comp = size;
        for(int i = 0; i < size; i++)
            parent[i] = i, rank[i] = 1;
    }
    
    ll Find(int u)
    {
        if(u == parent[u]) return u;
        return parent[u] = Find(parent[u]);
    }
    
    void Union(int u, int v)
    {
        ll root_u = Find(u), root_v = Find(v);
        if(root_u != root_v)
        {
            // ordering by rank
            if(rank[root_u] > rank[root_v])
                parent[root_v] = root_u;
            else if(rank[root_u] < rank[root_v])
                parent[root_u] = root_v;
            else
                parent[root_v] = root_u, rank[root_u]++;
            conn_comp--;
        }
    }
    
    int GetNumConnComp()
    {
        return conn_comp;
    }
    
    bool Connected(int u, int v){
        return Find(u) == Find(v);
    }
};
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        DSU dsu(n);
        sort(logs.begin(), logs.end());
        for(auto i : logs)
        {
            dsu.Union(i[1], i[2]);
            if(dsu.GetNumConnComp() == 1) return i[0];
        }
        return -1;
    }
};


















