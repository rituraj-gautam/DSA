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
        ListNode* temp = head;
	   
	  //count the length 
        int len = 0;
        while(temp!=NULL)
        {
            len++;
            temp = temp->next;
        }


        //find mid - actually mid position is mid (len/2)+1 but since we return Node so index of mid is (len/2)
        int mid = (len/2);
	  

        //take temp from head till mid pos and return temp 
        temp = head;

        while(mid--)
        {
            temp = temp->next;
            
        }

        return temp;
    }
};
