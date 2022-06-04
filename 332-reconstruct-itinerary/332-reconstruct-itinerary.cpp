class Solution {
public:
    vector<string> route;
    unordered_map<string, vector<string>> graph;
    
    void visit(string node)
    {
        while(graph[node].size() > 0)
        {
            string newNode = graph[node][0];
            graph[node].erase(graph[node].begin());
            visit(newNode);
        }
        route.push_back(node);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        for(auto i : tickets)
        {
            graph[i[0]].push_back(i[1]);
            if(graph.find(i[1]) == graph.end()) graph[i[1]] = {};
        }
        for(auto i = graph.begin(); i != graph.end(); i++)
            sort(i->second.begin(), i->second.end());
        
        string src = "JFK";
        visit(src);
        return vector<string>(route.rbegin(), route.rend());
    }
};