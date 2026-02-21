class Solution {
public:

    bool check(vector<vector<int>>& graph,  vector<int>&vis,vector<int>&colors,int currCol,int node){
        if(colors[node]!=-1) return colors[node]==currCol;
       
        colors[node]=currCol;
        for(auto& it :graph[node]){
            if(!check(graph,vis,colors,!currCol,it)) return false;
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>colors(n,-1);
        for(int i=0;i<n;i++){
            if(colors[i]==-1){
                if(!check(graph,vis,colors,0,i)) return false;
            }
        }

        return true;
    }
};