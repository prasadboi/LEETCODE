/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
        Convert the infix to postfix form
        Use the postfix expression to build the tree
    */
    int getPriority(char s)
    {
        if(s == '*' or s == '/') return 2;
        else if(s == '(') return -1;
        else return 1;
    }
    string convInfixToPostfix(string str)
    {
        stack<char> s;
        string ans;
        for(auto i : str){
            if(isdigit(i) == true){
                ans+=i;
            }
            else{
                if(i == '(') s.push(i);
                else if(i == ')'){
                    while(s.top() != '('){ans += s.top(); s.pop();} s.pop();
                }
                else{
                    int p = getPriority(i);
                    while(s.size() and p <= getPriority(s.top())){ans += s.top(); s.pop();}
                    s.push(i);
                }
            }
        }
        while(s.size()){ans += s.top(); s.pop();}
        cout<<"postfix : "<<ans<<endl;
        return ans;
    }
    
    Node* convertPostfixToTree(string str)
    {
        stack<Node*> s;
        for(auto i : str)
        {
            // if number then must be a leaf node
            if(isdigit(i)){
                Node* t = new Node(i); s.push(t);
            }
            else{
                Node* r = s.top(); s.pop();
                Node* l = s.top(); s.pop();
                Node* root = new Node(i);
                root->left = l; root->right = r;
                s.push(root);
            }
        }
        return s.top();
    }
    
    Node* expTree(string s) {
        string postfix = convInfixToPostfix(s);
        return convertPostfixToTree(postfix);
    }
};