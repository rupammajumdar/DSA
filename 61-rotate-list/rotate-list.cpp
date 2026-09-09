class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Base cases: empty list, single node, or no rotation needed
        if (!head || !head->next || k == 0) {
            return head;
        }
        ListNode* curr =head;

      int cnt=1;
      while(curr->next!=NULL){
        cnt++;
        curr=curr->next;

      }
      curr->next=head;
      k= k%cnt;
      int newstep=cnt-k;
      ListNode* temp=curr->next;
      while(newstep!=1){
        temp=temp->next;
        newstep--;
      }
      ListNode* NewHead = temp->next;
      temp->next=NULL;
      return NewHead;

    }
};