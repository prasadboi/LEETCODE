class Solution {
public:
    #define ll long long int
    
    int maxProduct(vector<int>& nums) {
        ll maxProdSoFar = nums[0], minProdSoFar = nums[0];
        ll res = nums[0];
        for(auto i = 1; i < nums.size(); i++){
            ll maxPSF = maxProdSoFar, minPSF = minProdSoFar;
            maxProdSoFar = max({maxPSF*nums[i], minPSF*nums[i], (ll)nums[i]});
            // cant use the maxProdSoFar vaariable as it has already been updated            
            minProdSoFar = min({maxPSF*nums[i], minPSF*nums[i], (ll)nums[i]}); 
            res = max(res, maxProdSoFar);
        }
        return res;
    }
};