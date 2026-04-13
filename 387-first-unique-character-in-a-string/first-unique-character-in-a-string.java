class Solution {
    public int firstUniqChar(String s) {
        List<Integer>freq=new ArrayList<>(Collections.nCopies(26,0));

        for(int i=0;i<s.length();i++){
           int index=s.charAt(i)-'a';
           freq.set(index,freq.get(index)+1);
        }

        for(int i=0;i<s.length();i++){
             int index=s.charAt(i)-'a';
             if(freq.get(index)==1) return i;
        }


        return -1;

    }
}