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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* intersection=NULL;   // to store final answer
        ListNode* p1=headA;
        ListNode *p2=headB;
       
        //get length of 1st ll
        int c1=0,c2=0;
        while(p1!=NULL){
            c1++;
            p1=p1->next;
            
        }
     
        //get length of second ll
        
         while(p2!=NULL){
                c2++;
            p2=p2->next;
         
        }
       
        //place both at head of ll
        
        p1=headA;
        p2=headB;
        
        if(c1>=c2){
            //move p1 
          for(int i=0;i<c1-c2;i++){
              p1=p1->next;
          }
        }
        
       else{
            //move p2 
          for(int i=0;i<c2-c1;i++){
              p2=p2->next;
          }
        }
        
        //now move both together
        
        
        
        
        while(p1!=NULL && p2!=NULL){
            
            if(p1==p2){
                intersection=p1;
                break;
            }
                
            p1=p1->next;
            p2=p2->next;
        }
        
        
        return intersection;
    }
};