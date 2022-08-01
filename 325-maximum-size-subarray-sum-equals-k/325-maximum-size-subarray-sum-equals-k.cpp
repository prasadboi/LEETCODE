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
            // cout<<"i = "<<i<<", sum = "<<sum<<endl;
            if(sum == k){
                // cout<<"i = "<<i<<", sum = "<<sum<<endl;
                res = max(res, (ll)i + 1);
            }
            else if(prefix.count(sum - k) > 0) {
                // cout<<"i = "<<i<<", sum = "<<sum<<", sum - k at : "<<prefix[sum-k]<<endl;
                res = max(res, (ll)i - prefix[sum-k]);
            }
            if(prefix.count(sum) <= 0) {
                // cout<<"i = "<<i<<", new sum = "<<sum<<endl;
                prefix[sum]=  i;
            }
        }
        return res;
    }
};