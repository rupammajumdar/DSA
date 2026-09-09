class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Base cases: empty list, single node, or no rotation needed
        if (!head || !head->next || k == 0) {
            return head;
        }

        // 1. Find the length of the list and the original tail node
        ListNode* curr = head;
        int len = 1;
        while (curr->next != NULL) {
            len++;
            curr = curr->next;
        }

        // 2. Connect the tail to the head to form a circular linked list
        curr->next = head;

        // 3. Calculate effective rotations
        k = k % len;
        
        // 4. Find the new tail, which is (len - k) steps from the current head
        int stepsToNewTail = len - k;
        ListNode* newTail = curr; // We can continue from the current tail
        while (stepsToNewTail > 0) {
            newTail = newTail->next;
            stepsToNewTail--;
        }

        // 5. Break the circle to establish the new head and tail
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};