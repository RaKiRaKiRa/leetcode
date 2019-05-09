/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int step = 1, len = 0;
        ListNode *cur = head, *left, *right, *pre = new ListNode(0), *tail = pre;
        pre -> next = head;
        while(head != NULL){
            ++len;
            head = head -> next;
        }
        for( ;step < len; step <<= 1){
            tail = pre;
            cur = pre -> next;
            while(cur){
                left = cur;
                right = split(left, step);
                cur = split(right, step);
                tail = merge(left, right, tail);
            }
        }
        head = pre -> next;
        delete pre;
        return head;
    }
    ListNode* split(ListNode* p, int step){
        for(int i = 1; p && i < step; ++i)
            p = p -> next;
        if(!p) return NULL;
        ListNode* t = p -> next;
        p -> next = NULL;
        return t;
    }

    ListNode* merge(ListNode* l, ListNode* r, ListNode* tail){
        while(l && r){
            if(l -> val < r -> val){
                tail -> next = l;
                l = l -> next;
                tail = tail -> next;
            }
            else{
                tail -> next = r;
                r = r -> next;
                tail = tail -> next;
            }
        }
        tail -> next = l ? l : r;
        while(tail -> next) tail = tail -> next;
        return tail;
    }
};

