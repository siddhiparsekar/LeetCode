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
    TreeNode* searchBST(TreeNode* root, int val) {
//         ITERATIVE
//         if(root==NULL || root->val==val)return root;
//         while(root && root->val!=val){
//             root=(root->val>val)?root->left:root->right;
//         }
//         return root;
        
        // RECURSIVE
        if (root == NULL) return root;
        if (val < root->val) return searchBST(root->left, val);
        if (val > root->val) return searchBST(root->right, val);
        
        return root;
        
    }
};