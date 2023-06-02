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
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
    
       ListNode* fast = head->next;
       ListNode* slow = head;
       

	//fast moves 2 steps and slow moves one step but if fast cant move 2 steps, i.e fast -> next = NULL then move 1 step and slow also by 1 step
      //so instead of writing fast = fast- > next -> next we check if fast = NULL if not then move 1 step again if fast = NULL then move 1 step again

       while(fast != NULL)
       {
           fast = fast->next;

           if(fast != NULL)
           {
               fast = fast->next;
           }

           slow = slow->next;       
           
        }
		
	//slow will reach mid so return slow

       return slow;
    }
};
