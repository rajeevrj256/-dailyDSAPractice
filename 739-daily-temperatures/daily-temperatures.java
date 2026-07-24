class Solution {
    public int[] dailyTemperatures(int[] temperatures) {


        int n=temperatures.length;
        int[] ans= new int[n];

        Stack<Integer>st=new Stack<>();
        int j=n-1;

        while(j>=0){
            while(!st.empty() && temperatures[j]>=temperatures[st.peek()]){
                st.pop();
                
            }
             if(st.empty()) ans[j]=0;
             else ans[j]=st.peek()-j;
            st.add(j);
            j--;
        }

        
        return ans;
    }
}
