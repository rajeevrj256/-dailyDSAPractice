class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character,Integer>hash=new HashMap<>();

        int i=0;
        int j=0;
        int n=s.length();
        int maxLen=0;

        while(j<n){
            char ch=s.charAt(j);
            while(hash.containsKey(ch)){
               hash.remove(s.charAt(i));
               i++;
            }

            hash.put(ch,j);

            maxLen=Math.max(maxLen,j-i+1);

            j++;
        }


        return maxLen;
    }
}