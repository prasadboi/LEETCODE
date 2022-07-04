class Solution {
public:
    #define vi vector<int>
    #define vvi vector<vi>
    #define ll long long int
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vi> s;
        for(auto i = 0; i < nums.size(); i++)
        {
            ll l = i+1, r = nums.size() - 1;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] == 0){
                    vi temp = {nums[i], nums[l], nums[r]};
                    s.insert(temp);
                    l++, r--;
                }
                else if(nums[i] + nums[r] + nums[l] < 0) l++;
                else r--;
            }
        }
        vvi res(s.begin(), s.end());
        return res;
    }
};