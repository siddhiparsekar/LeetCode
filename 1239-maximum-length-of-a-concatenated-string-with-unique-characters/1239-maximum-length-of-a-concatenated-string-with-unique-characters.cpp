class Solution {
public:
    bool compare(vector <int>&selected,string currstring){
        vector<int>selfchecker(26,0);
        for(int j=0;j<currstring.length();j++){
            if(selfchecker[currstring[j]-'a']==1)return false;
            selfchecker[currstring[j]-'a']=1;
        }
        for(int j=0;j<currstring.length();j++){
            if(selected[currstring[j]-'a']==1)return false;
            
        }
        return true;
    }
    int help(int i,vector<string>& arr,vector <int>&selected,int len){
        if(i==arr.size()){
            return len;
        }
        string currstring=arr[i];
        if(compare(selected,currstring)==false){
            return help(i+1,arr,selected,len);
        }
        else{
            //pick
            for(int j=0;j<currstring.length();j++){
                selected[currstring[j]-'a']=1;
            }
            len+=currstring.length();
            int len1=help(i+1,arr,selected,len);
            
            //not pick
            for(int j=0;j<currstring.length();j++){
                selected[currstring[j]-'a']=0;
            }
            len-=currstring.length();
            int len2=help(i+1,arr,selected,len);
            
            return max(len1,len2);
        }
        
    }
    int maxLength(vector<string>& arr) {
        vector<int>selected(26,0);
        return help(0,arr,selected,0);
        
    }
    
};

