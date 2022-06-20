class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.size();
        int max_len = 1; int maxStr = 0;
        for(int i = 0; i < s.size(); i++)    
        {
            if(i > 0 and i < n-1 and s[i-1] == s[i+1])
            {
                int l = i-1, r = i+1, len = 1;
                while(l > -1 and r < n and s[l] == s[r]) l--,r++, len+=2;
                if(len > max_len){
                maxStr = l+1;
                max_len = len;
                }
            }
            if(i > 0 and s[i-1] == s[i]){
                int l = i-1, r = i, len = 0;
                while(l > -1 and r < n and s[l] == s[r]) l--,r++, len+=2;
                if(len > max_len){
                maxStr = l+1;
                max_len = len;
                }
            }
        }
        cout<<"maxStr = "<<maxStr<<" \n max_len = "<<max_len<<endl;
        return s.substr(maxStr, max_len);
    }
};