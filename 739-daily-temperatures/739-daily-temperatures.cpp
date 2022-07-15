class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vi vector<int>
    
    vector<int> dailyTemperatures(vector<int>& temp) {
        // ans[i] is the number of days you have to wait after the ith day to get a warmer temperature
        // therefore,
        // ans[i] = (index of first element larger than i to the right of i) - i; 
        int n = temp.size();
        vi ans(n, 0);
        // we can do this using a stack
        stack<ll> s;
        // iterating over the array from right to left and updating the largest element encountered yet
        for(auto i = n-1; i >= 0; i--)
        {
            // find the first element larger than i to the right of i
            while(s.size() and temp[s.top()] <= temp[i]) s.pop();
            if(s.size() == 0) ans[i] = 0;
            else ans[i] = (int)(s.top() - i);
            s.push(i);
        }
        return ans;
    }
};