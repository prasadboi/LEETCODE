class Solution {
public:
    #define ll long long int
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        ll x = 0;
        for(auto i = 0; i < coins.size() and  coins[i] <= x+1; i++)
            x += coins[i];
        return x+1;
    }
};