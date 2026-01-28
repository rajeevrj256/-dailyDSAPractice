class Solution {
public:
    int calculate(string s) {
        long result = 0;
        char last_operator='+';
        int curr=0;
        int last=0;

        for(int i=0;i<s.size();i++){
            char c=s[i];

            if(isdigit(c)){
                curr=curr*10+(c-'0');
            }

            if(!isdigit(c) && !isspace(c) || i==s.size()-1){
                if(last_operator=='+'){
                      result += last;
                      last=curr;
                }else if (last_operator=='-'){
                    result += last;
                    last=-curr;
                }else if(last_operator=='*'){
                   
                    last=last*curr;
                }else if(last_operator=='/'){
                    last=last/curr;
                }
                last_operator=c;
                curr=0;


            }
        }

        


        return result+last;
    }
};