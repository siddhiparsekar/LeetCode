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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
//    //NAIVEL APPROACH -> TC= O(n)+O(n)      
//         if(!head)return head;
//         if(head->next==NULL && n==1)return NULL;
        
//         ListNode* ptr=head;
//         int l=0;
//         while(ptr){
//             l++;
//             ptr=ptr->next;
//         }
        
//         ptr=head;
//         int t=abs(l-n);
//         if(t==0)head=head->next;
//         while(t>1){
//             ptr=ptr->next;
//             t--;
//         }
//         ptr->next=ptr->next->next;
//         return head;  
        
        
   //OPTIMAL APPROACH -> TC= O(n)     
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        for(int i=1; i<=n; i++)
            fast = fast->next;
        
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        return dummy->next;
    }
};