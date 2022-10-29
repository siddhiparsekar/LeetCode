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
    vector<int> preorder;
    void preordert(TreeNode* root){
        if(root==NULL)
            return;
        preorder.push_back(root->val);
        preordert(root->left);
        preordert(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
//         ITERATIVE TRAVERSAL
//          vector<int> preorder;
//         stack<TreeNode*>st; 
//         if(root==NULL)return preorder;
        
//         st.push(root);
//         while(!st.empty()){
//             root=st.top();
//             st.pop();
//             preorder.push_back(root->val);
            
//             if(root->right!=NULL)
//                 st.push(root->right);
            
//             if(root->left!=NULL)
//                 st.push(root->left); 
//         }
//         return preorder;
        
//         RECURSIVE TRAVERSAL
        
        preordert(root);
        return preorder;
    }
};