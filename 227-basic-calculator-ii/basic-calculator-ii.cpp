class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        char last_operator='+';
        int curr=0;

        for(int i=0;i<s.size();i++){
            char c=s[i];

            if(isdigit(c)){
                curr=curr*10+(c-'0');
            }

            if(!isdigit(c) && !isspace(c) || i==s.size()-1){
                if(last_operator=='+'){
                      st.push(curr);
                }else if (last_operator=='-'){
                    st.push(-curr);
                }else if(last_operator=='*'){
                    int top=st.top();
                    st.pop();
                    st.push(top*curr);
                }else if(last_operator=='/'){
                    int top=st.top();
                    st.pop();
                    st.push(top/curr);
                }
                last_operator=c;
                curr=0;


            }
        }

        int ans=0;
        while(!st.empty()){
           ans+=st.top();
           st.pop();
        }


        return ans;
    }
};