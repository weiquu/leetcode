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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbersHelper(l1, l2, 0);
    }

public:
    ListNode* addTwoNumbersHelper(ListNode* l1, ListNode* l2, int carryOver) {
        if (l1 == NULL && l2 == NULL) {
            if (carryOver == 0) {
                return NULL;
            } else {
                return new ListNode(carryOver);
            }
        } else if (l1 == NULL) {
            // only l2 left
            int nextVal = l2->val + carryOver;
            if (nextVal < 10) {
                return new ListNode(nextVal, addTwoNumbersHelper(l1, l2->next, 0));
            } else {
                return new ListNode(nextVal - 10, addTwoNumbersHelper(l1, l2->next, 1));
            }
        } else if (l2 == NULL) {
            // only l1 left
            int nextVal = l1->val + carryOver;
            if (nextVal < 10) {
                return new ListNode(nextVal, addTwoNumbersHelper(l1->next, l2, 0));
            } else {
                return new ListNode(nextVal - 10, addTwoNumbersHelper(l1->next, l2, 1));
            }
        } else {
            //both left
            int nextVal = l1->val + l2->val + carryOver;
            if (nextVal < 10) {
                return new ListNode(nextVal, addTwoNumbersHelper(l1->next, l2->next, 0));
            } else {
                return new ListNode(nextVal - 10, addTwoNumbersHelper(l1->next, l2->next, 1));
            }
        }
    }
};