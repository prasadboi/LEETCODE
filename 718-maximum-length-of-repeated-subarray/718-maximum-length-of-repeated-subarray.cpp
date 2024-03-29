class Solution {
public:
    
    #define ll long long int
    #define INF (ll)(1e9 + 7)
    #define vll vector<ll>
    #define umap unordered_map
    #define vi vector<int>
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int dp[n1+1][n2+1];
        int ans = 0;  // store maximum length of subarray 
        for(int i=0; i<=n1; i++){
            for(int j=0; j<=n2; j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];  
                    ans = max(ans, dp[i][j]);
                }
                else dp[i][j] = 0; 
            }
        }
        return ans;
    }
};