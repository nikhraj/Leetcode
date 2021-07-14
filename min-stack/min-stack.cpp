class MinStack {
public:
    /** initialize your data structure here. */
    stack <array<int,2>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(!st.empty())
        {
            int mini = min(st.top()[1],val);
            st.push({val,mini});
        }
        else
            st.push({val,val});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top()[0];
    }
    
    int getMin() {
        return st.top()[1];
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