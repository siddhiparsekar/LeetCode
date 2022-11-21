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
    bool check(TreeNode* leftnode, TreeNode* rightnode){
        
        if(!leftnode && !rightnode)return true;
        if(!leftnode && rightnode)return false;
        if(leftnode && !rightnode)return false;
        
        bool l=check(leftnode->left,rightnode->right);
        if(l==false)return false;
        bool r=check(leftnode->right,rightnode->left);
        if(r==false)return false;
        
        if(leftnode->val!= rightnode->val)return false;
        
        return true;
        
        
    }
    bool isSymmetric(TreeNode* root) {
        
        return check(root->left,root->right);
        
    }
};