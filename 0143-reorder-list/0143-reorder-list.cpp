/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(): val(0), next(nullptr) {}
 *     ListNode(int x): val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next): val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;  // short lists no change

        // 1. Find middle (slow will point to midpoint)
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half
        ListNode* second = slow->next;
        slow->next = nullptr;  // split first half
        ListNode* prev = nullptr;
        while (second) {
            ListNode* nxt = second->next;
            second->next = prev;
            prev = second;
            second = nxt;
        }
        // now prev is head of reversed second half

        // 3. Merge two halves
        ListNode* first = head;
        ListNode* secondRev = prev;
        while (secondRev) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = secondRev->next;
            first->next = secondRev;
            secondRev->next = tmp1;
            first = tmp1;
            secondRev = tmp2;
        }
    }
};
