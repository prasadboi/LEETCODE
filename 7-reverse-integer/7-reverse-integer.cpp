class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x)
        {
            int lastDig = x%10;
            x /= 10;
            if((rev == INT_MAX/10 and lastDig > 7) or (rev > INT_MAX/10)) return 0;
            if((rev == INT_MIN/10 and lastDig < -8) or (rev < INT_MIN/10)) return 0;
            
            rev *= 10;
            rev += lastDig;
        }
        return rev;
    }
};