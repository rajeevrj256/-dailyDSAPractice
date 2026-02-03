class CustomStack {
public:
    stack<int>st;
    int maxsize;
    CustomStack(int maxSize) {
        maxsize=maxSize;
       
    }
    
    void push(int x) {
        if(st.size()==maxsize) return;
        st.push(x);
    }
    
    int pop() {
        if(st.empty()) return -1;
        int val=st.top();
        st.pop();
        return val;
    }
    
    void increment(int k, int val) {
        stack<int>temp;

        int steps=st.size()-k;
        if(steps<0) steps=0;

        while(steps){
              temp.push(st.top());
              st.pop();
              steps--;
        }
        while(!st.empty() ){
            int val_front=st.top();
            st.pop();
            temp.push(val_front+val);
          
        }

        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */