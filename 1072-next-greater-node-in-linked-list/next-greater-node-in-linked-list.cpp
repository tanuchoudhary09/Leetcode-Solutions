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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>A;
        stack<int>st;
        while(head){
            A.push_back(head->val);
            head = head->next;
        }
        int n = A.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && A[st.top()]<A[i]){
                int val = st.top();
                st.pop();
                ans[val] = A[i];
            }
            st.push(i);
        }
        return ans;
    }
};