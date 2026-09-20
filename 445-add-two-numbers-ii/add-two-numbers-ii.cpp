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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        vector<int>v1,v2;
        while(temp1){
            v1.push_back(temp1->val);
            temp1 = temp1->next;
        }
        while(temp2){
            v2.push_back(temp2->val);
            temp2=temp2->next;
        }
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        vector<int>v;
        int y = 0;
        int m = v1.size(),n=v2.size();
        for (int i=0;i<min(m,n);i++){
            int sum = v1[i]+v2[i] + y;
            y=0;
            v.push_back(sum%10);
            if(sum>9) y=1;
        }
        if(m>n){
            for(int i=n;i<m;i++){
                int k = v1[i]+ y;
                y=0;
                v.push_back(k%10);
                if(k>9) y=1;
            }
        }else{
            for(int i=m;i<n;i++){
                int k = v2[i]+ y;
                y=0;
                v.push_back(k%10);
                if(k>9) y=1;
            }
        }
        if(y) v.push_back(1);
        reverse(v.begin(), v.end());
        ListNode *head = new ListNode(v[0]);
        ListNode *temp = head;
        for(int i = 1; i < v.size() ; i++){
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }
        return head;
    }
};