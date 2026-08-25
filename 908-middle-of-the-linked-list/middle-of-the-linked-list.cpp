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
    ListNode* middleNode(ListNode* head) {
        int cnt=1;
        ListNode* curr=head;
        while(curr->next!=NULL){
            cnt++;
            curr=curr->next;
        }
        if(cnt%2==0){
            for(int i=1; i<((cnt/2)+1); i++ ){
                head=head->next;

            }
        }
        else{
            for(int i=1; i<=cnt/2; i++){
                head=head->next;
            }
        }
        return head;
        

    }
};