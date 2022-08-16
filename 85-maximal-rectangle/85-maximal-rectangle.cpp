class Solution {
public:
    #define ll long long int
    #define vll vector<ll>
    #define vvll vector<vll>
    
    ll LargestHistogram(vll &arr)
    {
        stack<ll> s; s.push(-1);
        ll res = 0;
        for(auto i = 0; i < arr.size(); i++)
        {
            while(s.top() != -1 and arr[i] < arr[s.top()]){
                ll h = arr[s.top()];
                s.pop();
                ll w = i - s.top() - 1;
                res = max(res, h*w);
            }
            s.push(i);
        }
        while(s.top() != -1)
        {
            ll h = arr[s.top()];
            s.pop();
            ll w = arr.size() - s.top() - 1;
            res = max(res, h*w);
        }
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        ll m = matrix.size(), n = matrix[0].size();
        vvll mat(m, vll(n, 0));
        for(auto i = 0; i < m; i++)
        {
            for(auto j = 0; j < n; j++)
            {
                mat[i][j] = matrix[i][j] - '0';
                if(i > 0 and matrix[i][j] == '1') mat[i][j] += mat[i-1][j];
            }
        }
        
        // for(auto i : mat) {for(auto j : i) cout<<j<<" "; cout<<endl;}
        
        ll res = 0;
        for(auto i = 0; i < m; i++){
            res = max(res, LargestHistogram(mat[i]));
        }
        return (int)res;
    }
};