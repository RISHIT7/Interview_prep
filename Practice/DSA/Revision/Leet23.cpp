class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        // merging two linked list with their head
        ListNode*c=new ListNode(-1);
        ListNode*temp=c;
        while(a!=NULL && b!=NULL) {
            if(a->val <= b->val) {
                temp->next=a;
                a=a->next;
                temp=temp->next;
            }
            else{
                temp->next=b;
                b=b->next;
                temp=temp->next;
            }
        }
        if(a==NULL) temp->next=b;
        else temp->next=a;
        return c->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& arr) { // heads of 'k' linked lists stored in-> arr
        if(arr.size()==0) return NULL;
        // method -> 1 - time complexity O(n.klogk)
        while(arr.size()>1) {
            ListNode*a=arr[0];
            arr.erase(arr.begin()); // removing 1st element form vector -> method
            ListNode*b=arr[0];
            arr.erase(arr.begin()); // removing 1st element form vector -> method
            ListNode*c=merge(a,b);
            arr.push_back(c);
        }
        // method -> 2 - time complexity O(n.k^2)
        while(arr.size()>1) {
            ListNode*a=arr[arr.size()-1];
            arr.pop_back();
            ListNode*b=arr[arr.size()-1];
            arr.pop_back();
            ListNode*c=merge(a,b);
            arr.push_back(c);
        }
        return arr[0];
    }
};
