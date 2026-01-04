class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>hash;

        for(string str:strs){
            vector<int>freq(26,0);
            for(char c:str){
                freq[c-'a']++;
            }

            string hashValue;

            for(int i=0;i<26;i++){
                hashValue+='#'+to_string(freq[i]);
            }
            hash[hashValue].push_back(str);
        }

        vector<vector<string>>ans;
        for(auto it:hash){
            ans.push_back(it.second);
        }

        return ans;
    }
};