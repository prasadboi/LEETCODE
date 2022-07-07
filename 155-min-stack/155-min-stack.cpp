class MinStack {
    stack<int> s;
    stack<int> mins;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(mins.empty() or val <= mins.top()) mins.push(val);
        s.push(val);
    }
    
    void pop() {
        if(s.empty()) return;
        if(mins.top() == s.top()) mins.pop();
        s.pop();  
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() 
    {
        // cout<<"getting Min : "<<endl;
        if(mins.empty()){cout<<"empty\n"; return INT_MAX;}
        // cout<<mins.top()<<endl;
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */