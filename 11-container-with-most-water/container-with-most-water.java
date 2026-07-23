class Solution {
    public int maxArea(int[] heights) {
        int i=0;
        int n=heights.length;


        int j=n-1;
        int maxContainer=0;
        while(i<j){
           int containerArea=Math.min(heights[i],heights[j])*(j-i);
           maxContainer=Math.max(maxContainer,containerArea);
          
           if(i<j && heights[i]<heights[j])i++;
           else{
            j--;
           }
        }


        return maxContainer;
    }
}