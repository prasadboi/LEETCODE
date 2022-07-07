class Solution {
public:
    #define vi vector<int>
    #define vvi vector<vi>
    #define vb vector<bool>
    #define ll long long int
    #define INF (1e9+7)
    
    void combo(int i, set<vi> &res, vi temp, int sum, vi &c, int target){
        if(sum == target) {res.insert(temp);}
        if(sum > target) return;
        for(auto j = i; j < c.size(); j++){
            temp.push_back(c[j]);
            combo(j, res, temp, sum + c[j], c, target);
            temp.pop_back();
        }
     }
    
    vector<vector<int>> combinationSum(vector<int>& c, int target) 
    {
        int n = c.size();
        set<vi> res;
        vi temp;
        sort(c.begin(), c.end());
        combo(0, res, temp, 0, c, target);
        vvi retres(res.begin(), res.end());
        return retres;
    }
};