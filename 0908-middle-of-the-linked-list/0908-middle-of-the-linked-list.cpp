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
        ListNode* first = head;
        ListNode* second = head;
        // if(head->next != nullptr && head->next->next != nullptr) 
        //     second = head->next->next;
        while(second != nullptr && second->next != nullptr){
            first = first->next;
            second = second->next->next;
            
        }
        return first;
    }
};