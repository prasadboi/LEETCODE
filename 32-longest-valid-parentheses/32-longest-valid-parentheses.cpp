class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int>> st;
        st.push({')', -1});
        int res = 0, n = s.size();
        for(int i = 0; i < n; i++)
        {
            if(s[i] == ')'){
                if(st.top().first == '('){
                    st.pop();
                    res = max(res, i - st.top().second);
                }
                else st.push({')', i});
            }
            else st.push({'(', i});
        }
        return res;
    }
};