#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> stack_locked;
        stack<int> stack_unlocked;

        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0') {
                stack_unlocked.push(i);
            } else if (s[i] == '(') {
                stack_locked.push(i);
            } else {
                if (!stack_locked.empty()) {
                    stack_locked.pop();
                } else if (!stack_unlocked.empty()) {
                    stack_unlocked.pop();
                } else {
                    return false;
                }
            }
        }

        while (!stack_locked.empty() && !stack_unlocked.empty() &&
               stack_locked.top() < stack_unlocked.top()) {
            stack_locked.pop();
            stack_unlocked.pop();
        }

        if (!stack_locked.empty()) {
            return false;
        }

        return stack_unlocked.size() % 2 == 0;
    }
};
