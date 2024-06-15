struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int len = 0;
        for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
            len++;
        }
        // Get hold of the mid of the linked list
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (len % 2 != 0) slow = slow->next;
        ListNode* secondHlfHead = reverse(slow);
        while (head != nullptr && secondHlfHead != nullptr) {
            if (head->val != secondHlfHead->val) return false;
            head = head->next;
            secondHlfHead = secondHlfHead->next;
        }
        return true;
    }
    
private:
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};