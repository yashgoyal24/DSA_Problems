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
        
       
        ListNode* slow=head;
        ListNode* fast=head;
        int counter=n;
        
        while(counter>=1){
            fast=fast->next;
            counter--;
        }
        
        // move slow and fast together till fast->next!=NULL
        
        if(fast==NULL){ // reached end
            return head->next;
        }
        
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
     return head;   
    }
};