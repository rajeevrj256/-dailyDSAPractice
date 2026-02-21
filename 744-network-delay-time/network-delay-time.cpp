class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        
        int m=times[0].size();
        for(int i=0;i<times.size();i++){
           
                int u=times[i][0];
                int v=times[i][1];
                int wt=times[i][2];
                adj[u].push_back({v,wt});
               
            
        }

        vector<int>res(n+1,INT_MAX);
        res[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});

        while(!q.empty()){
            auto [wt,node]=q.top();
            q.pop();
          
            for(auto &it:adj[node]){
                int adjNode=it.first;
                int adjWt=it.second;
                if(wt+adjWt<res[adjNode]){
                    res[adjNode]=wt+adjWt;
                    q.push({wt+adjWt,adjNode});
                }
            }

           
          
        }
       int minTime=0;
       for(int i=1;i<=n;i++){
        if(res[i] == INT_MAX)
                return -1;
        minTime=max(minTime,res[i]);
       }

       return minTime;
    }
};