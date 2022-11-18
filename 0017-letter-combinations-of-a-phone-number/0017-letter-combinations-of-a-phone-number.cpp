class Solution {
public:
    void help(int i,vector<string>&ans,string digits,string&temp, unordered_map<char,string>mp){
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }
        
        string str=mp[digits[i]];
        for(int j=0;j<str.length();j++){
            temp.push_back(str[j]);
            help(i+1,ans,digits,temp,mp);
			
			//Bactracking
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        vector<string>ans;
        string temp;
        if(digits==""){
            return ans;
        }
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        
        help(0,ans,digits,temp,mp);
        return ans;
    }
    
};