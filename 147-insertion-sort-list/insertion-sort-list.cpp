class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)return head;
        ListNode* temp = new ListNode(-5001);
        ListNode* dummy = temp;
        ListNode* ntP = head->next->next;//so that we dont process the head which has chnged
        if (head->val > head->next->val) {
            dummy->next = head->next;
            dummy->next->next = head;
        }else dummy->next = head;
        dummy->next->next->next = nullptr;
        dummy = dummy->next->next;
        head = ntP;
        while (head) {
            ListNode* nextNode = head->next;
            ListNode* temp1 = temp;
            ListNode* temp2 = temp->next;
            bool flag = false;
            while (temp2 != nullptr) {
                if (head->val < temp2->val) {
                    temp1->next = head;
                    head->next = temp2;
                    flag = true;
                    break;
                }
                temp1 = temp2;
                temp2 = temp2->next;
            }
            if (!flag) {
                temp1->next = head;
                head->next = nullptr;
                dummy = head;
            }
            head = nextNode;
        }
        ListNode* result = temp->next;
        return result;
    }
};
// class Solution {
// public:
//     ListNode* insertionSortList(ListNode* head) {
//         ListNode* temp = new ListNode(-5001);
//         ListNode* dummy = temp;
//         if(!head || !head->next) return head;
//         if(head->val>head->next->val){
//             dummy->next = head;
//             dummy->next->next = head->next;
//         }else{
//             dummy->next = head->next;
//             dummy->next->next = head;
//         }
//         head = head->next->next;
//         dummy = dummy->next;
//         while(head->next && head){
//             ListNode *temp1 = temp;
//             ListNode *temp2 = temp->next;
//             ListNode *curr = dummy;
//             while(curr->next && curr){
//                 if(temp1->val>temp2->val){
//                     curr->next = temp2;
//                     temp2->next = temp1;
//                     curr=temp1;
//                 }else break;
//                 curr = curr->next;
//                 temp1 = curr;temp2 = curr->next;
//             }
//             dummy = dummy->next;dummy->next=head;
//             head = head->next;
//         }
//         return temp->next;
//     }
// };
