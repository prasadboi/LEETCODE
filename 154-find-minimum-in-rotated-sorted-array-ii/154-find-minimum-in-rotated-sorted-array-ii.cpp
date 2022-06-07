class Solution {
public:
    #define ll long long int
    int findMin(vector<int>& nums) 
    {
        ll n = nums.size(), l = 0, r = n-1;
        while(l + 1 < r)
        {
            ll m = l + (r-l)/2;
            // in case we dont know where to go simply shorten the search space
            if(nums[m] == nums[l] and nums[m] == nums[r]){l++; r--;}
            else if(nums[(n + m-1)%n] > nums[m] and nums[m] < nums[(m+1)%n]) return nums[m];
            else if(nums[m] > nums[r]) l = m;
            else r = m;
        }
        
        if(nums[l] <= nums[(l+1)%n] and nums[l] <= nums[(n+l-1)%n]) return nums[l];
        if(nums[r] <= nums[(r+1)%n] and nums[r] <= nums[(n+r-1)%n]) return nums[r];
        return -1;
    }
};