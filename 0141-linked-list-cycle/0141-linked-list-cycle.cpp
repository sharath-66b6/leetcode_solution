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
    bool hasCycle(ListNode *head) {
        ListNode* x = head;
        ListNode* y = head;

        while(x != nullptr && y != nullptr && y->next != nullptr){
            x = x->next;
            y = y->next->next;
            if(x == y) return true;
        }
        return false;
    }
};