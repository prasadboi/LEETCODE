class Solution {
public:
    #define vvi vector<vector<int>> 
    #define vi vector<int>
    #define vb vector<bool>
    
    void getSet(int i, int n, vi nums, vvi &res, vi set)
    {
        res.push_back(set);
        for(int j = i; j < n; j++)
        {
            if(j == i or nums[j] != nums[j-1]){
                set.push_back(nums[j]);
                getSet(j+1, n, nums, res, set);
                set.pop_back();
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vvi res; vi set;
        getSet(0, nums.size(), nums, res, set);
        return res;
    }
};