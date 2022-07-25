class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int l = 0, n = s.size(), r = n-1;
        int swaps = 0;
        while(l < r)
        {
            if(s[l] == s[r]) l++, r--;
            else{
                string s1 = s, s2 = s;
                int leftswaps = 0, rightswaps = 0;

                int i = l+1; for(; s1[i] != s1[r] and i < r; i++);
                while(i != l){swap(s1[i], s1[i-1]); leftswaps++; i--;}
                
                int j = r-1; for(; s2[j] != s2[l] and j > l; j--);
                while(j != r){swap(s2[j], s2[j+1]); rightswaps++; j++;}
                
                if(leftswaps < rightswaps) s = s1;
                else s = s2;
                
                swaps += min(leftswaps, rightswaps);
            }
        }
        return swaps;
    }
};