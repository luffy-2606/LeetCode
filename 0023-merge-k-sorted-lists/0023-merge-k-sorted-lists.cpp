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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (true) {
            int minIndex = -1;       //to store the index of the current list from which smallest vlaue is taken from
            int minValue = INT_MAX;  //so that first element value is automatically assigned in first loop

            for (int i = 0; i < lists.size(); i++) {
                if ((lists[i] != nullptr) && (lists[i]->val < minValue)) {
                    minValue = lists[i]->val;
                    minIndex = i;
                }
            }

            if (minIndex == -1) //empty lists or end of lists
                break;

            //appending smallest into our list 
            tail->next = lists[minIndex];
            tail = tail->next;

            lists[minIndex] = lists[minIndex]->next;
        }

        return dummy->next;
    }
};