class Solution {
    public int helper(int n){
        int sum=0;

        while(n>0){
            int digit=n%10;
            n=n/10;
            sum+=(digit*digit);
        }

        return sum;
    }
    public boolean isHappy(int n) {
        HashSet<Integer>st=new HashSet<>();
        st.add(n);
        while(n!=1){
            n=helper(n);
            if(st.contains(n)) return false;
            st.add(n);
        }

        return true;
    }
}
