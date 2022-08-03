class Solution {
public:
    #define ll long long int
    
    int threeSumClosest(vector<int>& nums, int target) {
        ll res = -1, minDiff = INT_MAX, n = nums.size();
        sort(nums.begin(), nums.end());
        for(auto i = 0; i < n; i++)
        {
            ll sum = nums[i];
            for(ll l = i+1, r = n-1; l < n and r < n and l < r;){
                if(minDiff > abs(sum + nums[l] + nums[r] - target)){
                    res = sum + nums[l] + nums[r];
                    minDiff = abs(sum + nums[l] + nums[r] - target);
                    // cout<<"res = "<<res<<", iminDiff = "<<minDiff<<endl;
                }
                if(sum + nums[l] + nums[r] < target) l++;
                else r--;
            }
        }
        return res;
    }
};