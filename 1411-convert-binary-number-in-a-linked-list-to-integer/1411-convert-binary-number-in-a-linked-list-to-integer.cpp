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
    int getDecimalValue(ListNode* head) {
        string s = "";
        ListNode* node = head;
        while(node != nullptr){
            s += to_string(node->val);
            node = node->next;
        }

        int num=0,base=1;
        while(s.size() > 0){
            int rem = (s[s.size()-1] == '1')? 1:0;
            num += rem*base;
            s.erase(s.size()-1);
            base *= 2;
        }
        return num;
    }
};