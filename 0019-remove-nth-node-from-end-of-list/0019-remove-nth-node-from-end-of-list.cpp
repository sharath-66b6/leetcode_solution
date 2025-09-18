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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ans = new ListNode(0,head);
        ListNode* x = ans;
        ListNode* y = ans;
        
        int i=n+1;
        while(i--){
            x = x->next;
        }

        while(x != nullptr){
            x = x->next;
            y = y->next;
        }

        y->next = y->next->next;
        return ans->next;
    }
};