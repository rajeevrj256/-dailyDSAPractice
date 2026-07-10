class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length()!=t.length()) return false;
        HashMap<Character,Integer>hash=new HashMap<>();
        for(char c: s.toCharArray()){
            hash.put(c,hash.getOrDefault(c,0)+1);
        }
        for(char c:t.toCharArray()){
            hash.put(c,hash.getOrDefault(c,0)-1);
            if(hash.get(c)<0) return false;
        }

        return true;
    }
}