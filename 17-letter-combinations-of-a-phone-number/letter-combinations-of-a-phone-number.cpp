class Solution {
public:

    void backtrack(string digits, vector<string>&mp,int index,string res,vector<string>&ans){
        if(index==digits.size()){
            ans.push_back(res);
            return;
        }
       string letter=mp[digits[index]-'0'];
        for(char c:letter){
           res.push_back(c);
            backtrack(digits,mp,index+1,res,ans);
            res.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string>ans;
        backtrack(digits,mp,0,"",ans);
return ans;


    }
};