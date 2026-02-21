class Solution {
public:
int minPrice=INT_MAX;
    void dfs(int node, vector<vector<pair<int,int>>>& adj,int dst,int k,int cost){
        if(k<0) return;

        if(node==dst) {
            minPrice=min(minPrice,cost);
            return;
        }

        for(auto &it:adj[node]){
            if(cost+it.second >= minPrice) continue;

            dfs(it.first,adj,dst,k-1,cost+it.second);
        }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];
            adj[u].push_back({v,wt});
        }
       priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>qp;
       qp.push({0,src,0});
       vector<int>stop(n,INT_MAX);
        while(!qp.empty()){
            auto top=qp.top();
            qp.pop();
            int cost=top[0];
            int node=top[1];
            int step=top[2];
            if(node==dst) return cost;

            if(step>k || step>stop[node]) continue;
            stop[node]=step;
            for(auto &it:adj[node]){
                qp.push({cost+it.second,it.first,step+1});
            }
        }
        
        return minPrice==INT_MAX?-1:minPrice;
    }
};