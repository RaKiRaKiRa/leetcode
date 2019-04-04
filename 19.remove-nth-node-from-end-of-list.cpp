/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.09%)
 * Total Accepted:    370.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head ->next ==NULL)
            return NULL;
        ListNode *pre = head, *cur = head;
        int i = 0;
        while(i < n){
            //cout<<cur->val;
            cur = cur -> next;
            ++i;
        }
        //cout<<cur -> val;
        while(cur && cur -> next){
            //cout<<cur->val<<pre->val<<endl;
            pre = pre -> next;
            cur = cur -> next;
        }
        if (!cur) 
            return head->next;
        //cout<<cur->val;
        cur = pre -> next;
        pre -> next = cur -> next;
        //cout<<cur->val;
        delete cur;
        return head;
    }
};

