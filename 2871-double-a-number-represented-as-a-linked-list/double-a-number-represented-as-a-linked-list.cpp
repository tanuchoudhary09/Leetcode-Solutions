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
    ListNode* doubleIt(ListNode* head) {
        ListNode *list = new ListNode(1);
        if(!head->next){
            ListNode *dummy = new ListNode((head->val * 2)%10);
            list->next = dummy;
            if(head->val < 5) return list->next;
            return list;
        }
        bool flag = false;
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        if(head->val > 4){
            list->next = head;
            flag = true;
        }
        while(temp2){
            if(temp2->val >= 5) temp1->val = (temp1->val * 2)%10+1;
            else temp1->val = (temp1->val*2)%10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp1->val = (temp1->val * 2)%10;
        if(flag) return list;
        return head;
    }
};