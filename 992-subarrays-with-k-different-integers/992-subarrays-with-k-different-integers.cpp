class Solution {
public:
    #define ll long long int
    #define umap unordered_map
    int subarraysWithKDistinct(vector<int>& nums, int k)
    {
        ll l1 = 0, l2 = 0, r = 0, n = nums.size();
        ll ans = 0;
        umap<ll, ll> M1, M2;
        while(l1 <= r and l2 <= r and r < n)
        {
            M1[nums[r]]++;
            M2[nums[r]]++;
            while(M1.size() > k){
                if(--M1[nums[l1]] == 0) M1.erase(nums[l1]);
                l1++;
            }
            while(M2.size() >= k){
                if(--M2[nums[l2]] == 0) M2.erase(nums[l2]);
                l2++;
            }
            ans += (l2 - l1);
            r++;
        }
        return ans;
    }
};