class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        unordered_map<char,int>hash;

        for(char ch:t){
            hash[ch]++;
        }

        int i=0;
        int n=s.size();
        int j=0;
        int startIndex=0;
        int maxLen=INT_MAX;
        int count=0;
        while(j<n){
           if(hash[s[j]]>0){
            count++;
           }
           hash[s[j]]--;

           while(count==t.size()){
             if(j-i+1<maxLen){
                maxLen=j-i+1;
                startIndex=i;
             }
             hash[s[i]]++;

             if(hash[s[i]]>0) count--;

             i++;
           }

           j++;
        }

        return (maxLen==INT_MAX?"":s.substr(startIndex,maxLen));

    }
};