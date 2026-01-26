class Solution {
public:
    vector<int>nextSmallerRight(vector<int>&heights){
        int n=heights.size();
        vector<int>ans(n,-1);

        stack<int>st;

        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }else{
                ans[i]=n;
            }
            st.push(i);
        }

        return ans;
    }
     vector<int>nextSmallerLeft(vector<int>&heights){
        int n=heights.size();
        vector<int>ans(n,-1);

        stack<int>st;

        
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }else{
                ans[i]=-1;
            }
            st.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nseL=nextSmallerLeft(heights);
        vector<int>nseR=nextSmallerRight(heights);
 int n=heights.size();
        int largestArea=0;

        for(int i=0;i<n;i++){
            int height=heights[i];
            int breath=(nseR[i]-nseL[i]-1);
            largestArea=max(largestArea,height*breath);
        }

        return largestArea;
    }
};