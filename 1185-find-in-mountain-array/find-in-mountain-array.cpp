/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeakingElemenet(MountainArray &arr){
        int n=arr.length();
        int i=0;
        int j=n-1;

        while(i<j){
            int mid=i+(j-i)/2;

            if(arr.get(mid)<arr.get(mid+1)){
                i=mid+1;
            }else{
                j=mid;
            }
        }

        return i;
    }

    int findTarget(int target, MountainArray &arr,int i,int j,bool asc){

        while(i<=j){
            int mid=i+(j-i)/2;

             if (arr.get(mid) == target) return mid;
            if(asc){
                if(arr.get(mid)<target){
                    i=mid+1;
                }else{
                    j=mid-1;
                }
            }else{
                if(arr.get(mid)>target){
                    i=mid+1;
                }else{
                    j=mid-1;
                }
            }
        }

        return -1;

    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak=findPeakingElemenet(mountainArr);
        int leftpart=findTarget(target,mountainArr,0,peak,true);

        if(leftpart!=-1) return leftpart;


        return findTarget(target,mountainArr,peak+1,mountainArr.length()-1,false);

    }
};