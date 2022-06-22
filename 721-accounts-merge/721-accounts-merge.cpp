class Solution {
public:
    #define vi vector<int> 
    #define ll long long int
    #define vll vector<ll>
    #define vb vector<bool>
    
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accountList) {
        int accountListSize = accountList.size();
        DSU dsu(accountListSize);
        
        // Maps email to their component index
        unordered_map<string, int> emailGroup;
        
        for (int i = 0; i < accountListSize; i++) {
            int accountSize = accountList[i].size();

            for (int j = 1; j < accountSize; j++) {
                string email = accountList[i][j];
                string accountName = accountList[i][0];
                
                // If this is the first time seeing this email then
                // assign component group as the account index
                if (emailGroup.find(email) == emailGroup.end()) {
                    emailGroup[email] = i;
                } else {
                    // If we have seen this email before then union this
                    // group with the previous group of the email
                    dsu.UNION(i, emailGroup[email]);
                }
            }
        }
    
        // Store emails corresponding to the component's representative
        unordered_map<int, vector<string>> components;
        for (auto emailIterator : emailGroup) {
            string email = emailIterator.first;
            int group = emailIterator.second;
            components[dsu.FIND(group)].push_back(email);
        }

        // Sort the components and add the account name
        vector<vector<string>> mergedAccounts;
        for (auto componentIterator : components) {
            int group = componentIterator.first;
            vector<string> component = {accountList[group][0]};
            component.insert(component.end(), componentIterator.second.begin(), 
                                              componentIterator.second.end()
                            );
            sort(component.begin() + 1, component.end());
            mergedAccounts.push_back(component);
        }
        
        return mergedAccounts;
    }
};