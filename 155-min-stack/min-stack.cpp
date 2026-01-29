class MinStack {
public:
    MinStack() {
        
    }
    stack<pair<int,int>>st;

    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }else{
            pair<int,int>front=st.top();
            st.push({val,min(front.second,val)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        pair<int,int>front=st.top();
        return front.first;
    }
    
    int getMin() {
        pair<int,int>front=st.top();
        return front.second;
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