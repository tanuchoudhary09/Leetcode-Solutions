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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(1);
        ListNode *temp = dummy;
        while(head){
            int k = 1;
            while(head->next && head && head->val == head->next->val){
                k++;
                head = head->next;
            }
            if(k<2){
                temp->next = head;
                temp=temp->next;
            }
            if(head)head=head->next;
        }
        temp->next=nullptr;
        return dummy->next;
    }
};