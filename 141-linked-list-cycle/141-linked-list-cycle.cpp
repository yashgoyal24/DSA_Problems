/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        //use slow and fast pointer to detect collision
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                // cycle present
                return true;
            }
        }
        return false;
    }
};