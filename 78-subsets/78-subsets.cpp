class Solution {
public:
    #define ll long long int
    #define vi vector<int>
    #define vvi vector<vi>
    
    vector<vector<int>> subsets(vector<int>& nums) {
        ll n = nums.size();
        vvi res;
        for(ll i = 0; i < (1 << n); i++)
        {
            vi temp;
            for(ll j = 0; j < n; j++)
                if((i>>j) & 1) temp.push_back(nums[j]);
            res.push_back(temp);
        }
        return res;
    }
};