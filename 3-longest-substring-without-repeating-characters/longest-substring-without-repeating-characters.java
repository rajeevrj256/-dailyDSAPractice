class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character>st=new HashSet<>();

        int i=0;
        int j=0;
        int n=s.length();
        int maxLen=0;
        while(j<n){
           if(!st.contains(s.charAt(j))){
            
           
            maxLen=Math.max(maxLen,j-i+1);
           }else{
            while(st.contains(s.charAt(j))){
                st.remove(s.charAt(i));
                i++;
            }
           }

          st.add(s.charAt(j));
              j++;

        }

        return maxLen;
    }
}
