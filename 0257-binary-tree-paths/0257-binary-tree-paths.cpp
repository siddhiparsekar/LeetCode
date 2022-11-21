/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findpath(TreeNode* root,vector<string>& ans,string str){
        
        if(!root->left && !root->right){
            ans.push_back(str+to_string(root->val));
            return;
        }
        
       
        
        if(root->left)
            findpath(root->left,ans,str+ std::to_string(root->val)+"->");
        if(root->right)
            findpath(root->right,ans,str + std::to_string(root->val) +"->");
        
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string>ans;
        string str="";
        findpath(root,ans,str);
        return ans;
    }
};