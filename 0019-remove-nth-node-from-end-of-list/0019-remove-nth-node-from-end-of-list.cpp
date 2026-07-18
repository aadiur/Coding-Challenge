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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL||head->next==NULL){
            return NULL;
        }

        ListNode*temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        if(cnt==n){
            ListNode*temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        ListNode*temp2=head;
        ListNode*prev=NULL;
        for(int i=0;i<cnt-n;i++){
            prev=temp2;
            temp2=temp2->next;
            

        }
        
        prev->next=temp2->next;
        temp2->next=NULL;
        return head;


        
    }
};