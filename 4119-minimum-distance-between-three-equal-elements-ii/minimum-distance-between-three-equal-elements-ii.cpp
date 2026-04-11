class Solution {
public:
    int findMiniWindow(vector<int>& indexs){
        int i = 0, j = 0;
        int n = indexs.size();
        int miniDist = INT_MAX;

        while (j < n) {
            // expand window
            if (j - i + 1 < 3) {
                j++;
            } 
            // window size == 3
            else if (j - i + 1 == 3) {
                int dist = 2*(indexs[j]-indexs[i]);  // ✅ correct logic
                miniDist = min(miniDist, dist);
                
                i++; // slide window
                j++;
            }
        }

        return miniDist;
    }

    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            ans[nums[i]].push_back(i);
        }

        int minAns = INT_MAX;

        for (auto &it : ans) {
            if (it.second.size() >= 3) {
                minAns = min(minAns, findMiniWindow(it.second));
            }
        }

        return minAns == INT_MAX ? -1 : minAns;
    }
};