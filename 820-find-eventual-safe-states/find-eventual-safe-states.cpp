class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>outdegree(n);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
           outdegree[i]=graph[i].size();
           for(int j=0;j<graph[i].size();j++){
            adj[graph[i][j]].push_back(i);

           }
        }

        queue<int>q;
        vector<int>ans;
        int i=0;
        for(int it:outdegree){
           if(it==0)
           {q.push(i);
           ans.push_back(i);
           }
           i++;

        }

        while(!q.empty()){
            int top=q.front();
            q.pop();

            for(auto it:adj[top]){
                outdegree[it]--;
                if(outdegree[it]==0) {
                    ans.push_back(it);
                    q.push(it);
                    }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};