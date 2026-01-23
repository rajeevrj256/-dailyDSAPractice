class MyQueue {
public:
    MyQueue() {
        
    }
    
    stack<int>inStack;
    stack<int>outStack;
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        if(outStack.empty()){
            while(!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

        int x=outStack.top();

        outStack.pop();

        return x;
    }
    
    int peek() {
        if(outStack.empty()){
            while(!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

        int x=outStack.top();

        return x;
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */