class MinStack {
    stack<int> s;
    deque<int> q;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(q.empty() or q.front() >= val) q.push_front(val);
        else q.push_back(val);
        s.push(val);
    }
    
    void pop() {
        if(s.empty()) return;
        if(q.front() == s.top()) q.pop_front();
        s.pop();  
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() 
    {
        cout<<"getting Min : "<<endl;
        if(q.empty()){cout<<"empty\n"; return INT_MAX;}
        cout<<q.front()<<endl;
        return q.front();
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