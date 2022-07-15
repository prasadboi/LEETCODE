class Solution {
public:
    #define ll long long int
    
    int maxProduct(vector<int>& nums) {
        ll maxProdSoFar = nums[0], minProdSoFar = nums[0];
        ll res = nums[0];
        for(auto i = 1; i < nums.size(); i++){
            ll temp = max({maxProdSoFar*nums[i], minProdSoFar*nums[i], (ll)nums[i]});
            minProdSoFar = min({maxProdSoFar*nums[i], minProdSoFar*nums[i], (ll)nums[i]});
            maxProdSoFar = temp;
            res = max(res, maxProdSoFar);
        }
        return res;
    }
};