class MinStack {
public:
    stack<int>st;
    stack<int>minSt;
    stack<int>tempSt;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty()){
            minSt.push(val);
        }else{
            while(!minSt.empty() &&  minSt.top()<val){
                tempSt.push(minSt.top());
                minSt.pop();

            }

            minSt.push(val);
            while(!tempSt.empty()){
                minSt.push(tempSt.top());
                tempSt.pop();
            }

        }
    }
    
    void pop() {
        int val=st.top();
        st.pop();
        while(!minSt.empty() && minSt.top()!=val){
            tempSt.push(minSt.top());
            minSt.pop();

        }

       if (!minSt.empty())
    minSt.pop();

while(!tempSt.empty()){
                minSt.push(tempSt.top());
                tempSt.pop();
            }

    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
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