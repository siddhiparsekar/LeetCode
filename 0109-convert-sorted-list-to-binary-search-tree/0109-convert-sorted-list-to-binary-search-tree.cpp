/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // TreeNode* helper(ListNode* head) 
        
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(!head)return NULL;
        if(!head->next)return new TreeNode(head->val);
        
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* pre=head;
        
        while(fast && fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=NULL;
        
        TreeNode* temp= new TreeNode(slow->val);
        temp->left=sortedListToBST(head);
        
        temp->right=sortedListToBST(slow->next);
        
        return temp;
        
    }
};