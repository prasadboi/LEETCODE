class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vi vector<int>
    #define umap unordered_map
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        umap<ll, ll> M;

        M[0] = 1;
        ll ctr = 0;
        vll prefix(n, 0);
            
        prefix[0] = nums[0];
        for(auto i = 0; i < n; i++){
            if(i > 0) prefix[i] = nums[i] + prefix[i-1];
            ctr += M[prefix[i] - k];
            M[prefix[i]]++;
        }
        return (int)ctr;
    }
};