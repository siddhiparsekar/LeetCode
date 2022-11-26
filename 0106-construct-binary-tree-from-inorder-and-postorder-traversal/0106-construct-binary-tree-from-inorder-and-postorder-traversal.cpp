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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        map<int,int>mp;
        
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
        return root;
    }
    TreeNode* build(vector<int>& inorder,int istart,int iend, vector<int>& postorder,int pstart,int pend,map<int,int>&mp){
        
        if(istart>iend || pstart>pend)return NULL;
        
        TreeNode* root=new TreeNode(postorder[pend]);
        
        int iRoot=mp[root->val];
        int numsleft=iRoot-istart;
        
        root->left=build(inorder,istart,iRoot-1,postorder,pstart,pstart+numsleft-1,mp);
        root->right=build(inorder,iRoot+1,iend,postorder,pstart+numsleft,pend-1,mp);
            
        return root;
    }
};