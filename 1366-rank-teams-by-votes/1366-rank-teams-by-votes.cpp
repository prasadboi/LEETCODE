class Solution {
public:
    
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    #define umap unordered_map
    #define pq priority_queue
    #define vstr vector<string>
    // ---------------------------------------------------------------------------------
    // Approach 1:
    // make a 2d frequency table
    string solve(vstr &votes)
    {   
        vector<pair<char, vll>> freq_table(26);
        for(auto i = 'A'; i <= 'Z'; i++) freq_table[i - 'A'].first = i;
        
        
        for(auto voter_ordering : votes){
            
            for(auto i = 0; i < voter_ordering.size(); i++)
            {
                // team voter_ordering[i] has been given position/ordering i in the 
                // ordering sequence
                freq_table[voter_ordering[i] - 'A'].second.push_back(i);
            }
        }
        
        
        
        for(auto i = freq_table.begin(); i != freq_table.end(); i++) sort(i->second.begin(), i->second.end());
        
        // compute the final ordering of the teams
        auto cmp = [](pair<char, vll> &a, pair<char, vll> &b){
            if(a.second != b.second) return a.second < b.second;
            else return a.first < b.first;
        };
        sort(freq_table.begin(), freq_table.end(), cmp);
        
        // get the resultant string
        string res = "";
        for(auto i : freq_table) if(i.second.size() > 0) res.push_back(i.first);
        return res;
    }

    // driver function
    string rankTeams(vector<string>& votes) {
        return solve(votes);
    }
};