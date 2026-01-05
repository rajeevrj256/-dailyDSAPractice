class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int j=n-1;

        while(i<j){
            int mid=(i+j)/2;

           if(nums[mid]>nums[j]){
            i=mid+1;
           }else{
            j=mid;
           }
        }

        return nums[i];
    }
};