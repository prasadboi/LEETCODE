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

void print_graph(vvll &graph)
{
    for(auto i : graph)
    {
        for(auto j : i) cout<<j<<" ";
        cout<<endl;
    }
}
//---------------------------------------------------------------------------------------------     
//---------------------------------------------------------------------------------------------     
vvi res;
void dfs(ll src, vvll &graph, vb &visited, vll &t_in, vll &low, ll &timer, ll parent = -1)
{
    // cout<<"called dfs -> "<<src<<endl;
    visited[src] = true;
    t_in[src] = low[src] = timer++;
    for (auto i : graph[src])
    {
        if (i == parent) // the edge leads back to the parent in the dfs tree
            continue;
        else if (visited[i] == true) // the edge is a back edge to one of the ancestors
        {
            low[src] = min(low[src], t_in[i]);
        }
        else // the edge is a part of the DFS tree and needs to be explored
        {
            dfs(i, graph, visited, t_in, low, timer, src);
            low[src] = min(low[src], low[i]);
            if (low[i] > t_in[src]){
                // cout << "the edge == " << src << "<->" << i << ", is a bridge\n";
                res.push_back({(int)src, (int)i});
            }
        }
    }
}
//---------------------------------------------------------------------------------------------     
//---------------------------------------------------------------------------------------------     
void find_bridges(ll n, vvll &graph)
{
    vb visited(n, false);
    vll t_in(n, -1), low(n, -1);
    ll timer = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, graph, visited, t_in, low, timer);
    }
}
//---------------------------------------------------------------------------------------------     
//---------------------------------------------------------------------------------------------     
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vvll graph(n);
        for(auto i : connections)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        find_bridges((ll)n, graph);
        return res;
    }
};