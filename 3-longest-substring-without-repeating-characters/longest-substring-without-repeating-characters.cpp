class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>hash;

        int i=0;
        int j=0;
         
        int maxLen=INT_MIN;
        while(j<s.length()){
            while(hash[s[j]]>0){
                hash[s[i]]--;
                i++;
            }

            maxLen=max(maxLen,j-i+1);
            hash[s[j]]++;
            j++;
        }

        return (maxLen==INT_MIN?0:maxLen);
    }
};