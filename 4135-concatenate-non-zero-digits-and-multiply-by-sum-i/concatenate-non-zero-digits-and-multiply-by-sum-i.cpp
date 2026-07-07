class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0;
        long long sumDigit=0;
        while(n>0){
           long long digit=n%10;
           n=n/10;
           if(digit!=0){
           sumDigit+=digit;
           x=10*x+digit;
           }
        }
        //reverse
        
        long long rev=0;
        while(x>0){
          rev=10*rev+(x%10);
          x=x/10;
        }
        return sumDigit*rev;
    }
};