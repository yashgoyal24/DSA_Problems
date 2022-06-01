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
    ListNode* reverseList(ListNode* head) {
        
        //iterative solution
        
        if(head==NULL)
            return head;
        
        //dummy node
        
        ListNode* d=NULL;
        ListNode* curr=head;
        ListNode* next=curr->next;
        
        while(next!=NULL){
            
            curr->next=d;
            d=curr;
            curr=next;
            next=curr->next;
            
            
        }
        
         curr->next=d;
        
        return curr;
        
        
        
    }
};