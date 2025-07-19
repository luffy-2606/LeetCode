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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) // if no nodes or just one node (base case)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Move "prev" to the node just before the "left" point
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* current = prev->next;  // now current is at the "left" node
        ListNode* next = nullptr;        // new temp node

        for (int i = 0; i < (right - left); i++) {
            next = current->next;
            current->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy->next;
    }
};
