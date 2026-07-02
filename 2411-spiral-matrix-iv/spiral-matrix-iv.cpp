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
    vector<vector<int>> spiralMatrix(int r, int c, ListNode* head) {
        int a = 0;
        int size = 0;
        int k = r*c;
        vector<vector<int>>matrix(r,vector<int>(c));
        while(1){
            for(int i=a;i<c;i++){
                if(head!=NULL)matrix[a][i]=head->val;
                if(head!=NULL)head=head->next;
                else matrix[a][i]=-1;
                size++;
            }
            if(size== k) break;
            for(int i=a+1;i<r;i++){
                if(head!=NULL)matrix[i][c-1]=head->val;
                if(head!=NULL)head=head->next;
                else matrix[i][c-1]=-1;
                size++;
            }
            if(size== k) break;
            for(int i=c-2;i>=a;i--){
                if(head!=NULL)matrix[r-1][i]=head->val;
                if(head!=NULL)head=head->next;
                else matrix[r-1][i]=-1;
                size++;
            }
            if(size==k) break;
            for(int i=r-2;i>=a+1;i--){
                if(head!=NULL)matrix[i][a]=head->val;
                if(head!=NULL)head=head->next;
                else matrix[i][a]=-1;
                size++;
            }
            if(size== k) break;
            r--;
            c--;
            a++;
        }
        return matrix;
    }
};