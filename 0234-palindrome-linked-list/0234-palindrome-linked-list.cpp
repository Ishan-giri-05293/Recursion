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
    bool isPalindrome(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // If odd length, move slow one step further
        if (fast) slow = slow->next;

        // Step 2: Reverse the second half
        ListNode* secondHalf = reverseList(slow);

        // Step 3: Compare both halves
        ListNode* firstHalf = head;
        ListNode* check = secondHalf;
        while (check) {
            if (firstHalf->val != check->val) return false;
            firstHalf = firstHalf->next;
            check = check->next;
        }

        return true;
    }

private:
    // Helper function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;        
        
    }
};