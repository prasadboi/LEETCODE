
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (auto i : s) {
            if (i == ']') 
            {
                string decodedString = "";
                // get the encoded string
                while (st.top() != '[') {
                    decodedString += st.top();
                    st.pop();
                }
                // pop [ from stack
                st.pop();
                int base = 1;
                int k = 0;
                // get the number k
                while (!st.empty() && isdigit(st.top())) {
                    k = k + (st.top() - '0') * base;
                    base *= 10;
                    st.pop();
                }
                // decode k[decodedString], by pushing decodedString k times into stack
                while (k != 0) {
                    for (int j = decodedString.size() - 1; j >= 0; j--) st.push(decodedString[j]);
                    k--;
                }
            }
            // push the current character to stack
            else st.push(i);
        }
        // get the result from stack
        string result;
        for (int i = st.size() - 1; i >= 0; i--) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};

