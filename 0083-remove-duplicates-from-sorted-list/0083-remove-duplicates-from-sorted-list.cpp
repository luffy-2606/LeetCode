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
        if (!head || !head->next) //empty case
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy->next;  

        while (current && current->next) {
            if (current->val == current->next->val) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;  
            } 
            else {
                current = current->next; //so that it only moves whenever it completely
                                         //removes the duplicates of the current digit
            }
        }

        return dummy->next;
    }
};