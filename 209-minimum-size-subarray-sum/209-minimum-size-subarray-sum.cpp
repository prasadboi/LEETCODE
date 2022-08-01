class Solution {
public:
    #define ll long long int
    #define umap unordered_map
    
    
    int minSubArrayLen(int target, vector<int>& nums) {
        map<ll, ll> prefix;
        prefix[0] = -1;
        ll sum = 0, res = INT_MAX;
        for(ll i = 0; i < nums.size(); i++){
            sum += nums[i];
            auto it = prefix.lower_bound(sum - target);
            if(it->first == sum - target){
                res = min(res, i - it->second);
            }
            else{
                if(it != prefix.end() and it->first > sum - target and it != prefix.begin()){
                    // cout<<"it->sfirst = "<<it->first<<endl;
                    --it;
                    res = min(res, i - it->second);
                }
                else if(it == prefix.end()) res = min(res, i + 1);
            }
            prefix[sum] = i;
        }
        
        // can also do 2 pointer approach on the prefix array. O(n) time. Best Solution
        return (res == INT_MAX) ? 0 : res;
    }
};