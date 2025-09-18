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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* mid = nullptr;
        ListNode* x = head;
        ListNode* y = head;
        
        while(y != nullptr && y->next  != nullptr){
            mid = x;
            x = x->next;
            y = y->next->next;
        }

        mid->next = nullptr;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(x);

        return merge(l1, l2);
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* p = new ListNode(0);
        ListNode* cur = p;

        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        if(l1 != nullptr){
            cur->next = l1;
        }
        if(l2 != nullptr){
            cur->next = l2;
        }

        return p->next;
    }
};