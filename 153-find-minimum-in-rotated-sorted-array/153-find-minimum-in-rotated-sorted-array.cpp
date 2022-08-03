class Solution {
public:
    #define ll long long int
    bool isValley(vector<int> &nums, ll idx){
        bool left = (nums[idx] <= nums[(idx-1 + nums.size())%nums.size()]);
        bool right = nums[idx] <= nums[(idx + 1)%nums.size()];
        return (left and right);
    }
    
    int findMin(vector<int>& nums) 
    {
        // template 3 binary  search
        ll l = 0, n = nums.size(), r = n-1;
        while(l + 1 < r)
        {
            ll m = l + (r-l)/2;
            if(isValley(nums, m)) return nums[m];
            else if(nums[m] > nums[r]) l = m;
            else r = m;
        }
        if(isValley(nums, l)) return nums[l];
        if(isValley(nums, r)) return nums[r];
        return -1;
    }
};