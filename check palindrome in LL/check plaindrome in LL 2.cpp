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
private:
    ListNode* getmid(ListNode* &head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;
        int cnt = 0;

        while(fast!= NULL)
        {
            fast=fast->next;
            if(fast!= NULL)
            {
                fast=fast->next;
            }
            slow = slow->next;
            cnt++;
        }
        cout<<cnt<<endl;
        return slow;

    }
    
    ListNode* rev(ListNode* &head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;


        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)
        {
            return true;
        }

        //find mid
        ListNode* mid = getmid(head);

        //rev after mid
        mid = rev(mid);

        //check for palindrome
        ListNode* curr1 = head;
        ListNode* curr2 = mid;

        while(curr2 != NULL)
        {
            if(curr1->val != curr2->val)
            {
                return false;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return true;
    }
};
