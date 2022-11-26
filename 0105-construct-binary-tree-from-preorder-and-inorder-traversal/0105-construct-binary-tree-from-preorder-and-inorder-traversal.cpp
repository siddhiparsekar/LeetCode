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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=build(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,mp);
        return root;
    }
    TreeNode* build(vector<int>& inorder,int istart,int iend,vector<int>& preorder, int pstart,int pend,map<int,int>&mp){
        
        if(pstart>pend || istart>iend)return NULL;
        
        TreeNode* root=new TreeNode(preorder[pstart]);
        
        int inRoot=mp[root->val];
        int numsleft= inRoot - istart;
        
        root->left= build(inorder, istart,inRoot-1,preorder,pstart+1,pstart+numsleft,mp);
        
        root->right=build(inorder,inRoot+1,iend,preorder,pstart+numsleft+1,pend,mp);
        
        return root;
        
    }

};