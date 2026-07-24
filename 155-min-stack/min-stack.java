class Pair{
    int first;
    int second;

    Pair(int first,int second){
        this.first=first;
        this.second=second;
    }
};

class MinStack {
    Stack<Pair>st=new Stack<>();
    int mini=Integer.MAX_VALUE;
    public MinStack() {
        
    }
    
    public void push(int val) {
         mini=Math.min(mini,val);
        st.push(new Pair(val,mini));
        
    }
    
    public void pop() {
        st.pop();

        if(st.empty()) mini=Integer.MAX_VALUE;

        else mini=st.peek().second;

    }
    
    public int top() {
        return st.peek().first;
    }
    
    public int getMin() {
        return st.peek().second;
    }
}
