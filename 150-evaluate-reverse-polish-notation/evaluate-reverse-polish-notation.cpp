class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int curr=0;
        for(int i=0;i<tokens.size();i++){
            string c=tokens[i];
            if(c=="+" || c=="-" || c=="*" || c=="/"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                int res=0;
                if(c=="+"){
                    res=first+second;
                }else if(c=="-"){
                    res=second-first;
                }else if(c=="*"){
                    res=second*first;
                }else {
                    res=second/first;
                }
                st.push(res);

            }else{
                st.push(stoi(c));
            }


        }
        return st.top();
    }
};