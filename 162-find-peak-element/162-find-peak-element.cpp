class Solution {
public:
    #define ll long long int
    int findPeakElement(vector<int>& nums) 
    {
        if(nums.size() == 1) return 0;
        if(nums.size() == 0) return -1;
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MIN);
        
        ll l = 1, r = nums.size() - 1;
        while(l < r)
        {
            ll m = l + (r-l)/2;
            if(nums[m] > nums[m-1] and nums[m] > nums[m+1]) return m-1;
            else if(nums[m] > nums[m-1] and nums[m] < nums[m+1]) l = m+1;
            else r = m;
        }
        if(l != nums.size() and nums[l] > nums[l-1] and nums[l] > nums[l+1]) return l-1;
        return -1;
    }
};