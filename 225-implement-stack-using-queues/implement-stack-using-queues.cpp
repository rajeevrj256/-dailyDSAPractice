class MyStack {
public:
    MyStack() {
        
    }
    queue<int>q;
    void push(int x) {
        q.push(x);
        int size=q.size();
        for(int i=0;i<size-1;i++){
            int top=q.front();
            q.pop();
            q.push(top);
        }
    }
    
    int pop() {
        int x=q.front();
        q.pop();

        return x;
    }
    
    int top() {
         int x=q.front();
        

        return x;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */