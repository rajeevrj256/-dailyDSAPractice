class Solution {
    public int[] plusOne(int[] digits) {
        
        int n=digits.length;
        digits[n-1]=(digits[n-1]+1);
        int carry=digits[n-1]/10;
        digits[n-1]=(digits[n-1])%10;
        n=n-2;
        while(carry==1 && n>=0){
            digits[n]=(digits[n]+carry);
            carry=digits[n]/10;
            digits[n]=(digits[n])%10;
            n--;
        }

      if (carry == 0) {
    return digits;
}

int[] ans = new int[digits.length + 1];
ans[0] = 1;

       return ans; 
    }
}
