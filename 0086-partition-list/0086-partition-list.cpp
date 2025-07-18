/*
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* beforeHead = new ListNode(0); // dummy node for < x
        ListNode* afterHead = new ListNode(0);  // dummy node for >= x

        ListNode* before = beforeHead;
        ListNode* after = afterHead;

        while (head) // loop till nodes exists
        {
            if (head->val < x) { // if "< x" then store it in before and increment before
                before->next = head;
                before = before->next;
            } else { // else store it in after and increment after
                after->next = head;
                after = after->next;
            }
            head = head->next;  // increment the loop
        }

        after->next = nullptr;         // End the new list (only add null to after as it would be the second half)
        before->next = afterHead->next;  // combince before and after 

        return beforeHead->next;
    }
};
