class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    
        vector<vector<pair<int, int>>> adj(n);


        vector<int>dist(n,INT_MAX);
        for(auto flight:flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }

        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        dist[src]=0;

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int step=node.first;
            int u=node.second.first;
            int cost=node.second.second;

            if(step>k) continue;

            for(auto it:adj[u]){
                int newCost=cost+it.second;
                if(dist[it.first]>newCost){
                    dist[it.first]=newCost;
                    q.push({step+1,{it.first,newCost}});
                }
                
            }

        }

        return dist[dst]==INT_MAX?-1:dist[dst];






    }
};