class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    bool isPlayerReach(pair<int,int>player,pair<int,int>target,pair<int,int>boxPos,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push(player);
        vis[player.first][player.second]=1;
        while(!q.empty()){
            auto[r,c]=q.front();
             int bx = boxPos.first;
             int by = boxPos.second;
            q.pop();
            if(r==target.first && c==target.second) return true;
            for(int i=0;i<4;i++){
                int nx=r+dx[i];
                int ny=c+dy[i];
                 if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                if(!vis[nx][ny] && grid[nx][ny]!='#' && !(nx==bx && ny==by) ){
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
        return false;

    }
    int minPushBox(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        pair<int,int>player,box,target;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='S') player={i,j};
                if(grid[i][j]=='B') box={i,j};
                if(grid[i][j]=='T') target={i,j};
            }
        }

        queue<vector<int>>q;
        set<string>vis;
        q.push({box.first,box.second,player.first,player.second,0});
        while(!q.empty()){
            auto curr=q.front();
            q.pop();

            int bx=curr[0];
            int by=curr[1];
            int px=curr[2];
            int py=curr[3];
            int pushes=curr[4];

            if(bx==target.first && by==target.second) return pushes;

            string key = to_string(bx)+","+to_string(by)+","+to_string(px)+","+to_string(py);
            if(vis.count(key)) continue;
            vis.insert(key);
            for(int i=0;i<4;i++){
                int nbx=bx+dx[i];
                int nby=by+dy[i];

                int npx=bx-dx[i];
                int npy=by-dy[i];
                if(nbx < 0 || nby < 0 || nbx >= n || nby >= m) continue;
                if(npx < 0 || npy < 0 || npx >= n || npy >= m) continue;

                if(grid[nbx][nby]=='#') continue;
                if(grid[npx][npy]=='#') continue;

                if(!isPlayerReach({px,py},{npx,npy},{bx,by},grid)){
                    continue;
                }


                q.push({nbx,nby,bx,by,pushes+1});

            }



        }



        return -1;
    }
};