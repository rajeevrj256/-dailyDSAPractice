class Solution {
public:
    bool check(string str1,string str2){
        int i=0;
        int n=str1.size();
        int j=0;
        int m=str2.size();
        if(n%m!=0) return false;
        for(int i=0;i<n;i++){
            if(str1[i]!=str2[i%m]) return false;
        }

        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        string prefix="";
        string ans="";
       if(str2.size() > str1.size())
            swap(str1, str2);
int i=0;
          while(i<str2.size()){
            prefix+=str2[i];
            if(check(str1,prefix) && check(str2,prefix)){
                ans=prefix;
            }
            i++;
          }

          return ans;
    }
};