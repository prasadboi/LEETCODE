class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int largestR = 0, res = 0;
        
        for(int i = prices.size()-1; i >= 0; i--){
            res = max(res, largestR - prices[i]);
            largestR = max(largestR, prices[i]);
        }
        return res;
    }
};