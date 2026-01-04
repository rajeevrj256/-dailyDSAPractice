class Solution {
public:
    string reverseWords(string s) {
        int j=s.length()-1;
        int i=j;
 string ans="";
        while(j>=0){
            while(j>=0 && s[j]==' '){
                j--;
            }
            if(j<0) break;
            i=j;
            while(i>=0 && s[i]!=' '){
                i--;
            }
            if (!ans.empty()) ans += ' ';
            ans+=s.substr(i+1,j-i);
           

            j=i-1;
        }

        return ans;
    }
};