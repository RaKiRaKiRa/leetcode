/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (46.36%)
 * Total Accepted:    541.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
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
/*struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;

        ListNode* res = new ListNode(0), *cur = res;
        while(l1 && l2){
            if(l1 -> val < l2 -> val){
                cur -> next = l1;
                cur = cur -> next;
                l1 = l1 -> next;
            }
            else{
                cur -> next = l2;
                cur = cur -> next;
                l2 = l2 -> next;
            }
        }
        if(l1)
            cur -> next = l1;
        else
            cur -> next = l2;
        
        return res -> next;
    }
};

