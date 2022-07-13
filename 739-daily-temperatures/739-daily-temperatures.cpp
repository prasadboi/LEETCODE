class Solution {
public:
    #define vi vector<int>
    #define long long int
    #define vll vector<ll>
    
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vi res(n, 0);
        stack<int> s;
        // for every index find the the closest index greater than it
        for(int i = n-1; i >= 0; i--)
        {
            while(s.size() and temp[s.top()] <= temp[i])
            {
                s.pop();
            }
            if(s.size()) res[i] = s.top() - i;
            else res[i] = 0;
            s.push(i);
        }
        return res;
    }
};