class Solution {
public:
    class DSU
    {
    public:
        unordered_map<string , pair<string, double>> parent;
        pair<string, double> Find(string nodeID)
        {
            if(parent.find(nodeID) == parent.end())
                parent[nodeID] = {nodeID, 1};
            
            string grpID = parent[nodeID].first;
            double nodeWt = parent[nodeID].second;
            
            if(grpID != nodeID)
            {
                pair<string, double> newGroup = Find(grpID);
                string newGrpID = newGroup.first; double grpWt = newGroup.second;
                parent[nodeID] = {newGrpID, nodeWt*grpWt};
            }
            return parent[nodeID];
        }
        
        void Union(string u, string v, double wt)
        {
            pair<string, double> dividend = Find(u), divisor = Find(v);
            if(dividend.first != divisor.first)
                parent[dividend.first] = {divisor.first, (divisor.second*wt)/dividend.second};
        }
    };
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        DSU dsu;
        for(int i = 0; i < equations.size(); i++){
            dsu.Union(equations[i][0], equations[i][1], values[i]);
        }
        
        vector<double> result;
        for(auto i : queries)
        {
            string u = i[0], v = i[1];
            if(dsu.parent.find(u) == dsu.parent.end() or dsu.parent.find(v) == dsu.parent.end())
            {result.push_back(-1); continue;}
            pair<string, double> dividend = dsu.Find(u);
            pair<string, double> divisor = dsu.Find(v);
            // cout<<"dividend_grp = "<<dividend.first<<", divisor_grp = "<<divisor.first<<endl;
            if(dividend.first != divisor.first) result.push_back(-1);
            else
            {
                result.push_back(dividend.second/divisor.second);
            }
        }
        return result;
    }
};