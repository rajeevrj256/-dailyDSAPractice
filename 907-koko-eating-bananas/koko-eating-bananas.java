class Solution {

    public boolean isValid(int[] piles,int h,int k){
         int currHr=0;
        
         for(int i=0;i<piles.length;i++){
            currHr=currHr+((piles[i]+k-1)/k);
           

             if(currHr>h) return false;
         }

         
         

     
     
      return true;
 
    }
    public int minEatingSpeed(int[] piles, int h) {
        int totalBanana=0;
         int j=0;
        for(int pile:piles){
            j=Math.max(j,pile);
        }

        int minK=0;
        int i=1;

      
        while(i<j){

            int mid=(j+i)/2;
            if(isValid(piles,h,mid)) {
               
                j=mid;    
            }else{
                i=mid+1;
            }

        }

        return i;
    }
}
