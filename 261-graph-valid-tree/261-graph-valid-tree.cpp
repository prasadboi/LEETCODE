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
private:
    vll parent;
    vll rank;
    ll count;

public:
    DSU(int n) : parent(n), rank(n)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i, rank[i] = 1;
        count = n;
    }

    ll Find(int u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = Find(parent[u]);
    }

    void Union(int u, int v)
    {
        ll root_u = Find(u), root_v = Find(v);
        if (root_u != root_v)
        {
            if (rank[root_u] > rank[root_v]) parent[root_v] = root_u;
            else if(rank[root_u] < rank[root_v]) parent[root_u] = root_v;
            else{
                parent[root_v] = root_u, rank[root_u]++;
            }
            count--;
        }
    }
    
    bool connected(int u, int v)
    {
        return Find(u) == Find(v);
    }

    ll get_count(){return count;}
};
    
//------------------------------------------------------------------------------------
    
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        DSU dsu(n);
        for(auto i : edges)
        {
            if(dsu.Find(i[0]) == dsu.Find(i[1])) return false;
            else{
                dsu.Union(i[0], i[1]);
            }
        }
        if(dsu.get_count() == 1) return true; else return false;
    }
//------------------------------------------------------------------------------------

};