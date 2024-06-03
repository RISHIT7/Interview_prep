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
        ListNode *travA = headA;
        ListNode *travB = headB;
        int lenA = 0;
        int lenB = 0;

        while (travA->next != NULL)
        {
            travA = travA->next;
            lenA++;
        }
        
        while (travB->next != NULL)
        {
            travB = travB->next;
            lenB++;
        }

        // now we check if there is intersection by comparing the last node
        if (travA != travB)
        {
            return NULL;
        }
        travA = headA;
        travB = headB;
        int diff = lenA - lenB;
        if (diff > 0)
        {
            while (diff > 0)
            {
                travA = travA->next;
                diff--;
            }
        }

        else if (diff < 0)
        {
            diff *= -1;
            while (diff > 0)
            {
                travB = travB->next;
                diff--;
            }
        }
        
        if (travA == travB)
        {
            return travA;
        }
        while (travA -> next != NULL && travA->next != travB->next)
        {
            travA = travA->next;
            travB = travB->next;
        }
        return travA->next;

    }
};
