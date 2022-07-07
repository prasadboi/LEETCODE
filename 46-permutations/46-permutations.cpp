class Solution {
public:
    #define vi vector<int>
    #define vvi vector<vi>
    #define INF (1e9+7)
    #define vb vector<bool>
    
    void permute(int i, vi &temp, vvi &res, vb &vis, vi &arr){
        if(i == arr.size()){res.push_back(temp); return;}
        for(auto j = 0; j < arr.size(); j++){
            if(vis[j]) continue;
            vis[j] = true;
            temp.push_back(arr[j]);
            permute(i+1, temp, res, vis, arr);
            temp.pop_back();
            vis[j] = false;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vvi res;
        vi temp;
        vb vis(nums.size(), false);
        permute(0, temp, res, vis, nums);
        return res;
    }
};