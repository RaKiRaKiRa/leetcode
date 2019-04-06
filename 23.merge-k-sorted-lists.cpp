/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (33.52%)
 * Total Accepted:    361.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Solution {
public:

    ListNode* merge2Lists(vector<ListNode*>& lists,int l,int r){
        if(l == r) return lists[l];
        ListNode *l1, *l2;
        if(l - r == 1){
            l1 = lists[l];
            l2 = lists[r];
        }    
        else{
            l1 = merge2Lists(lists, l, (l + r) / 2);
            l2 = merge2Lists(lists, (l + r) / 2 + 1, r);
        }
        ListNode *res = new ListNode(0), *pre = res;
        while(l1 && l2){
            //cout << l << r <<endl;
            if(l1 -> val < l2 -> val){
                res -> next = l1;
                l1 = l1 -> next;
                res = res -> next ; 
            }
            else{
                res -> next = l2;
                l2 = l2 -> next;
                res  = res -> next ; 
            }
        }
        if(l1){
            res -> next = l1;
        }
        if(l2){
            res -> next = l2;
        }
        res = pre -> next;
        delete pre;
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        return merge2Lists(lists, 0, lists.size() - 1);
    }
};

