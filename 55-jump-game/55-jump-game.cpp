/*
// O(N^2) solution:
// (T.L.E.)
class Solution {
public:
    #define vb vector<bool>
    #define vi vector<int>
    #define vvi vector<vi>
    #define ll long long int
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vb dp(n, false); dp[0] = true;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(i - j <= nums[j]) dp[i] = dp[i] or dp[j];
            }
        }
        return dp[n-1];
    }
};
*/

class Solution {
public:
    // the greedy solution is the most optimal one
    #define vb vector<bool>
    #define vi vector<int>
    #define vvi vector<vi>
    #define ll long long int
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        int jump = 0; // maxindex we can jump to
        for(int i = 0; i < n; i++){
            jump = max(jump, i + nums[i]);
            // if we reach a point 
            // where we can jump to the ith step (i != the last step)
            // but dont have enough energy to jump further on then we obv cant move forward. 
            // therefore return false;
            if(jump <= i and i < n-1) return false; 
        }
        return true;
    }
};