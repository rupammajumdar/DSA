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
    ListNode* deleteMiddle(ListNode* head) {
        int cnt=1;
        ListNode* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
            cnt++;
        }
        ListNode* temp=head;
        ListNode* deletedNode;
        if(cnt==2) {deletedNode=curr; temp->next=NULL; delete deletedNode; return temp ;}
        if(temp->next==NULL ) return NULL;
        for(int i=1; i<(cnt/2); i++){
            temp=temp->next;
        }
        
        deletedNode=temp->next;
        temp->next=temp->next->next;
        delete deletedNode;
        return head;
        



    }
};