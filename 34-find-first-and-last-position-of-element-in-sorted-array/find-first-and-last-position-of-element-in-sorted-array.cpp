class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        int firstIndex=-1;

        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target){
                firstIndex=mid;
                j=mid-1;
            }else if(nums[mid]>target){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }

         i=0;
         j=nums.size()-1;
        int lastIndex=-1;

        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target){
                lastIndex=mid;
                i=mid+1;
            }else if(nums[mid]<target){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }


        return {firstIndex,lastIndex};
    }

};