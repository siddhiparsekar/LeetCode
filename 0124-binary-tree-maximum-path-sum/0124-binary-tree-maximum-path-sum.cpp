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

    int maxPathSum(TreeNode* root) {
        
        int final_sum=INT_MIN; 
        sum(root,final_sum);
        return final_sum;
    }
    int sum(TreeNode* node,int& final_sum){
             
           if(node == NULL) return 0;
        
           int ls=INT_MIN,rs=INT_MIN,cs=INT_MIN; 
            
           ls =sum(node->left,final_sum);
           rs =sum(node->right,final_sum); 
           cs = node->val;
            
           final_sum = max({cs,cs+ls,cs+rs,cs+ls+rs,final_sum});
            
           return max({cs,cs+ls,cs+rs}); 
     
    }
    
};