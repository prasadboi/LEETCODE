class Solution {
public:
    #define vi vector<int>
    #define ll long long int
    #define vll vector<ll>
    
    vector<int> productExceptSelf(vector<int>& nums) {
        ll prod = 1, zero_freq = 0, prod_nozero = 1;
        for(auto i : nums) {if(i != 0){prod_nozero *= i;}else{zero_freq++;} prod *= i;}
        vi res;
        for(int i = 0; i < nums.size(); i++){
            if(zero_freq >= 2) res.push_back(0);
            else{
                if(nums[i] == 0) res.push_back(prod_nozero);
                else res.push_back((int)(prod/nums[i]));
            }
        }
        return res;
    }
};