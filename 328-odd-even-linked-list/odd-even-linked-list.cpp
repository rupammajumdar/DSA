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
    ListNode* oddEvenList(ListNode* head) {
       if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* odd =head;
        ListNode* even = head->next;
        ListNode* even_head = even;

    while (even != NULL && even->next != NULL) {
            // Odd ko agle odd se jodein aur pointer aage badhayein
            odd->next = even->next;
            odd = odd->next;
            
            // Even ko agle even se jodein aur pointer aage badhayein
            even->next = odd->next;
            even = even->next;
        }

        // Odd list ke end ko even list ke head se jod dein
        odd->next = even_head;

        return head;
    }
};