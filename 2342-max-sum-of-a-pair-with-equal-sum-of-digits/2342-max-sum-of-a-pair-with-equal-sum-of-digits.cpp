class Solution {
public:
    #define vi vector<int>
    #define umap unordered_map
    #define pq priority_queue
    
    int maximumSum(vector<int>& nums) {
        umap<int, pq<int>> samesum;
        int res = -1;
        for(auto i : nums)
        {
            int j = i;
            int digSum = 0;
            while(j){
                digSum += j%10;
                j = j/10;
            }
            if(samesum[digSum].size())res = max(res, i + samesum[digSum].top());
            samesum[digSum].push(i);
        }
        return res;
    }
};