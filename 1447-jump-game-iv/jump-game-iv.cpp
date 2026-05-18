class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<pair<int,int>> q;

        vector<bool> vis(n,false);

        q.push({0,0});

        vis[0] = true;

        while(!q.empty()) {

            auto front = q.front();
            q.pop();

            int node = front.first;
            int step = front.second;

            if(node == n - 1) {
                return step;
            }

            // i + 1
            if(node + 1 < n && !vis[node + 1]) {

                vis[node + 1] = true;

                q.push({node + 1, step + 1});
            }

            // i - 1
            if(node - 1 >= 0 && !vis[node - 1]) {

                vis[node - 1] = true;

                q.push({node - 1, step + 1});
            }

            // same value jumps
            for(auto it : mp[arr[node]]) {

                if(!vis[it]) {

                    vis[it] = true;

                    q.push({it, step + 1});
                }
            }

            // important optimization
            mp[arr[node]].clear();
        }

        return -1;
    }
};