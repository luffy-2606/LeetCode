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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* current = head;

        while (current) {
            if (current->next && (current->val == current->next->val)) // if next node exists && current node == next node
            {
                int duplicateVal = current->val; // store the dupe value
                while (current && (current->val == duplicateVal)) // move to the next node if current node is equal to the dupe value
                {
                    current = current->next;
                }
                prev->next = current; // When the dupe finishes, remove them by assigning the very next node to the previous node from start (now the dupe values are not being stored by anyone)
            } else {
                // else move forward
                prev = current;
                current = current->next;
            }
        }

        return dummy->next;
    }
};
