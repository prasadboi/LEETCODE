class Solution {
public:
    #define ll long long int
    #define umap unordered_map
    int maxSubArrayLen(vector<int>& nums, int k) {
        umap<ll, ll> prefix;
        ll sum = 0, res = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(sum == k){
                res = max(res, (ll)i + 1);
            }
            else if(prefix.count(sum - k) > 0) {
                res = max(res, (ll)i - prefix[sum-k]);
            }
            if(prefix.count(sum) <= 0) {
                prefix[sum]=  i;
            }
        }
        return res;
    }
};