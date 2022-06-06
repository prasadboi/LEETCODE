class Solution {
public:
    #define ll long long int
    #define vvll vector<vector<ll>>
    #define vll vector<ll>
    #define vb vector<bool>
    
    void print_graph(unordered_map<char, string> graph)
    {
        for(auto i : graph)
        {
            cout<<i.first<<"->"<<i.second<<endl;
        }
    }
    
    string alienOrder(vector<string>& words) 
    {
        unordered_map<char, string> graph;
        unordered_map<char, int> indegree;
        
        if(words.size() == 1)
        {
            for(auto i : words[0]) indegree[i] += 0;
        }
        
        
        for(int i = 0; i < words.size() - 1; i++)
        {
            ll n = min(words[i].size(), words[i+1].size());
            int j = 0;
            bool flag = false;
            for(j = 0; j < n; j++)
            {
                if(words[i][j] == words[i+1][j]){
                    graph[words[i][j]] += "";
                    indegree[words[i][j]] += 0;
                    indegree[words[i+1][j]] += 0;
                }
                else{
                    graph[words[i][j]] += words[i+1][j];
                    graph[words[i+1][j]] += "";
                    indegree[words[i][j]] += 0;
                    indegree[words[i+1][j]] += 1;
                    flag = true;
                    j++;
                    break;
                }
            }
            if((words[i].size() - j > words[i+1].size() - j) and flag == false) return "";
            int temp = j;
            for(; j < words[i].size(); j++){
                graph[words[i][j]] += ""; indegree[words[i][j]] += 0;
            }
            for(j = temp; j < words[i+1].size(); j++)
            {
                // cout<<"words[i+1][j] = "<<words[i+1][j]<<endl;
                graph[words[i+1][j]] += ""; indegree[words[i+1][j]] += 0;
            }
        }
        
        queue<char> q;
        string res = "";
        int ctr = 0;
        for(auto i : indegree)
        {
            if(i.second == 0 and i.first >= 'a' and i.first <= 'z') q.push(i.first);
            if(i.first >= 'a' and i.first <= 'z') ctr++;
        }
        while(!q.empty())
        {
            char u = q.front(); q.pop();
            res += u;
            for(auto v : graph[u])
            {
                if(--indegree[v] == 0) q.push(v);
            }
        }
        if(res.size() != ctr) return "";
        else return res;
    }
};