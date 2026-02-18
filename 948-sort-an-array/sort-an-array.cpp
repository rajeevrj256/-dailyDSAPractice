class Solution {
public:
   void merge(vector<int>&nums,int l,int mid,int r){
       vector<int>temp;
       int i=l;
       int j=mid+1;
       while(i<=mid && j<=r){
        if(nums[i]<=nums[j]){
            temp.push_back(nums[i]);
            i++;

        }else{
             temp.push_back(nums[j]);
        j++;
        }
       }

       while(i<=mid){
          temp.push_back(nums[i]);
            i++;
       }

       while(j<=r){
          temp.push_back(nums[j]);
            j++;
       }

       for(int k=l;k<=r;k++){
        nums[k]=temp[k-l];
       }
   }
    void mergeSort(vector<int>&nums,int i,int j){
        if(i>=j) return ;
        int mid=i+(j-i)/2;

        mergeSort(nums,i,mid);
        mergeSort(nums,mid+1,j);
        merge(nums,i,mid,j);
        
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);

        return nums;
        
        
    }
};