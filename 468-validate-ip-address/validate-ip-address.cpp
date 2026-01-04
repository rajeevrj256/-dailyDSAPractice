class Solution {
public:
    int stringtoInt(string num){
        int ans=0;
        int i=0;
        while(i<num.size()){
            int digit = num[i] - '0';

             if (ans > (255 - digit) / 10) {
            return 256;  // force invalid (>255)
        }
            ans=ans*10+(num[i]-'0');
            i++;
        }

        return ans;
    }
    bool checkIPv4(string queryId){
       int i=0;
       int j=0;
       int dots=0;
       while(j<=queryId.size()){
        if(j ==queryId.size() ||  queryId[j]=='.'){
            if(i==j) return false;
            if(j-i>3) return false;
            if (j - i > 1 && queryId[i] == '0') return false;
            
        string num=queryId.substr(i,j-i);
        int res=stringtoInt(num);
        if(res>255) return false;
        i=j+1;
        dots++;
       }else{
        if(!isdigit(queryId[j])) return false;
       }
        j++;
       }

       return dots==4;
    }
     bool checkIPv6(string queryId){
       int i=0;
       int j=0;
       int dots=0;
       while(j<=queryId.size()){
        if(j ==queryId.size() ||  queryId[j]==':'){
            if(i==j) return false;
            if(j-i>4) return false;
                    
        i=j+1;
        dots++;
       }else{
       if(!isxdigit(queryId[j])) return false;
       }
        j++;
       }

       return dots==8;
    }
    string validIPAddress(string queryIP) {
        string ans;
        int n=queryIP.size();
      
        bool checkIp4=checkIPv4(queryIP);     
        bool checkIp6=checkIPv6(queryIP);
        ans=(checkIp6 || checkIp4 ?(checkIp4?"IPv4":"IPv6"):"Neither");
       
        return ans;
    }
};