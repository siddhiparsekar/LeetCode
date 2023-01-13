class Solution {
public:
    void helper(int idx, string &s, vector<string>&str, vector<vector<string>>&res){
        if(idx == s.size()){  //BASE CASE
            res.push_back(str);
            return;
        }
        for(int i=idx; i<s.size(); i++){
            if(isPalindrome(s, idx, i)){
                str.push_back(s.substr(idx, i-idx+1));
                helper(i+1, s, str, res);
                str.pop_back();  //BACKTRACKING
            }
        }
    }
    bool isPalindrome(string s, int start, int end){ //CHECK WHETHER THE PASSED STRING IS PALINDROME OR NOT
        while(start<=end){
            if(s[start]!=s[end])return false;
            start++,end--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<string>str;
        vector<vector<string>>res;
        helper(0, s, str, res);
        return res;
    }
};