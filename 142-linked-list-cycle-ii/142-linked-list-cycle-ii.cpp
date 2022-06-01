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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* result=head;
        
        //If only 1 node or no nodes, return NULL since no cycle possible 
        
          if(head==NULL || head->next==NULL){
            return NULL;
        }
        
        
          //use slow and fast pointer to detect collision
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                while(slow!=result){
                    slow=slow->next;
                    result=result->next;
                }
                
                // now slow is equal to result, so return it
                return slow;
            }
        }
      
        
        return NULL;   // no entry point found
    }
};