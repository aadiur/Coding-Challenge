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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode*tail=head;
        int cnt=1;
        if(head==NULL||head->next==NULL||k==0){
            return head;
        }
        while(tail->next){
            cnt++;
            tail=tail->next;
        }
        
        k=k%cnt;
        if(k==0)return head;
        tail->next=head;
        ListNode*temp1=head;
        for(int i=0;i<cnt-k-1;i++){
            temp1=temp1->next;


        }
       ListNode*newHead=temp1->next;
       temp1->next=NULL;

        return newHead;
        
        
    }
};