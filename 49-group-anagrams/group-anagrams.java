class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,List<String>>hash=new HashMap<>();

        for(int i=0;i<strs.length;i++){
            String word=strs[i];
           
           int[] freq=new int[26];
            for(int j=0;j<word.length();j++){
               freq[word.charAt(j)-'a']++;

            }
StringBuilder key = new StringBuilder();;
            for(int j=0;j<26;j++){
                key.append(freq[j]);
                key.append('#');
            }
            
             String k = key.toString();
            if(!hash.containsKey(k)){
                hash.put(k,new ArrayList<>());
            }
            hash.get(k).add(word);
        }

       List<List<String>>ans= new ArrayList<>();
       for(List<String>list:hash.values()){
        ans.add(list);
       }

       return ans;
        
    }
}
