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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // handle edge cases like 0
        if (l1->val == 0 && l1->next == nullptr)
        {
            return l2;
        }
        else if (l2->val == 0 && l2->next == nullptr)
        {
            return l1;
        }
        bool carry=false;
        bool prev_carry = false;
        ListNode* trav1 = l1;
        ListNode* trav2 = l2;

        ListNode* check1 = l1;
        ListNode* check2 = l2;
        while (check2 != nullptr && check1 != nullptr)
        {
            check1 = check1->next;
            check2 = check2->next;
        }
        if (check1 == NULL && check2 != NULL)
        {
            return addTwoNumbers(l2, l1);
        }

        while (trav1 != nullptr || trav2 != nullptr)
        {
            if (trav1 == nullptr)
            {
                trav1 = new ListNode(0);
                if (prev_carry)
                {
                    trav1->val += 1;
                    prev_carry = false;
                }
            }
            else if (trav2 == nullptr)
            {
                trav2 = new ListNode(0);
                if (prev_carry)
                {
                    trav2->val += 1;
                    prev_carry = false;
                }
            }

            if (prev_carry)
            {
                trav1->val += 1;
            }

            if (trav1->val + trav2->val >= 10)
            {
                carry = true;
            }
            else
            {
                carry = false;
            }

            if (carry)
            {
                trav1->val = -10 + (trav1->val + trav2->val);
            }
            else
            {
                trav1->val = trav1->val + trav2->val;
            }

            trav1 = trav1->next;
            trav2 = trav2->next;
            prev_carry = carry;
        }
        if (prev_carry)
        {
            trav1 = l1;
            while (trav1-> next != nullptr)
            {
                trav1 = trav1->next;
            }
            trav1->next = new ListNode(1);
        }
        // if (trav1->val == 10)
        // {
        //     trav1->val -= 10;
        //     trav1->next = new ListNode(1);
        // }
        
        return l1;
    }
};
