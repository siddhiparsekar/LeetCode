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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
//         if(root==NULL)return NULL;
        
//         if(root->val==key)
//             return helper(root);
        
//         TreeNode* dummy =root;
//         while (root!=NULL){
            
//           if(root->val>key){
//             if(root->left!=NULL && root->left->val==key){
//                 root->left=helper(root->left);
//                 break;
//             }
//             else{
//                 root=root->left;
//             }
//           }
//           else{
//             if(root->right!=NULL && root->right->val==key){
//                 root->right=helper(root->right);
//                 break;
//             }
//             else{
//                 root=root->right;
//             }
//           }
//         }
//         return dummy;
//     }
//     TreeNode* helper(TreeNode* root){
//         if(root->left == NULL)
//             return root->right;
//         else if(root->right == NULL)
//             return root->left;
        
//         TreeNode* rightchild = root->right;
//         TreeNode* lastright = findlastright(root->left);
//         lastright->right = rightchild;
//         return root->left; 
//     }
//     TreeNode* findlastright(TreeNode* root){
//         if(root->right == NULL)
//             return root;
//         return findlastright(root->right);
//     }
        
        if(root){ 
            if(key < root->val) root->left = deleteNode(root->left, key);     //We frecursively call the function until we find the target node
            else if(key > root->val) root->right = deleteNode(root->right, key);       
            else{
                if(!root->left && !root->right) return NULL;          //No child condition
                if (!root->left || !root->right)
                    return root->left ? root->left : root->right;    //One child contion -> replace the node with it's child
					                                                //Two child condition   
                TreeNode* temp = root->left;                        //(or) TreeNode *temp = root->right;
                while(temp->right != NULL) temp = temp->right;     //      while(temp->left != NULL) temp = temp->left;
                root->val = temp->val;                            //       root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);  //        root->right = deleteNode(root->right, temp);		
            }
        }
        return root;
    }
};