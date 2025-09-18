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
        map<ListNode*, int> mp;

        while(headA != nullptr || headB != nullptr){
            if(headA != nullptr){ 
                mp[headA]++;
                if(mp[headA] > 1){
                    return headA;
                }
                headA = headA->next;
            }
            if(headB != nullptr) {
                mp[headB]++;
                if(mp[headB] > 1){
                    return headB;
                }
                headB = headB->next;
            }
            
        }
        return NULL;
    }
};