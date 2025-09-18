/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int even) : val(even), next(nullptr) {}
 *     ListNode(int even, ListNode *next) : val(even), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* even = head;
        ListNode* odd = head->next;
        ListNode* even_head = odd;

        while(odd != nullptr && odd->next != nullptr){
            even->next = even->next->next;
            even = even->next;
            odd->next = odd->next->next;
            odd = odd->next;
        }

        even->next = even_head;
        return head;
    }
};