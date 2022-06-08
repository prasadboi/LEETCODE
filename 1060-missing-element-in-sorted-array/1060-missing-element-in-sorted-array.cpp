class Solution {
public:
    #define ll long long int
    #define vi vector<int>
    #define vll vector<ll>
    
    ll misses(ll i, vi nums)
    {
        return (nums[i] - nums[0] - 1) -  (i-1);
    }
    
    int missingElement(vector<int>& nums, int k) 
    {
        ll n = nums.size();
        ll l = 0, r = n;
        if(k > misses(n-1, nums)) return nums[n-1] + (k - misses(n-1, nums));
        // find the 2 numbers such that the number of misses of one is less and the other is more than target k
        while(l < r)
        {
            ll m = l + (r-l)/2;
            cout<<"l = "<<l<<", m = "<<m<<", r = "<<r<<endl;
            if(misses(m, nums) < k and misses((m+1), nums) >= k)
            {
                return nums[m] + (k - misses(m, nums));
            }
            else if(misses(m, nums) < k) l = m + 1;
            else r = m;
            cout<<"l = "<<l<<", m = "<<m<<", r = "<<r<<endl<<"----------------"<<endl;
        }
        return -1;
    }
};