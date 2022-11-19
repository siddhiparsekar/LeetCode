class Solution {
public:
    bool isPalindrome(int x) {
        
        string str=to_string(x);
        int n=str.length();
        
        int i=0,j=n-1;
        while(i<j){
            if(str[i]!=str[j])return false;
            
            i++,j--;
        }
        return true;
    }
};