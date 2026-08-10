class Solution {

    public void helper(String s,String temp,List<String>ans,int index,int closing,int opening){
        if(closing>opening) return;
        if(temp.length()==s.length()) {
             ans.add(temp);
             return;
        }
      
        if(opening<s.length()/2){
        helper(s,temp+"(",ans,index+1,closing,opening+1);
        }

        if(closing<opening){
        helper(s,temp+")",ans,index+1,closing+1,opening);
        }
       
    }
    public List<String> generateParenthesis(int n) {
        StringBuilder s = new StringBuilder();
List<String>ans=new ArrayList<>();
        for(int i=0;i<n;i++){

            s.append("()");
        }

        String temp="";
        helper(s.toString(),temp,ans,0,0,0);

        return ans;

    }
}
