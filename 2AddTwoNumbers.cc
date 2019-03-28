/*
https://leetcode.com/problems/add-two-numbers/
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode  *res = new ListNode(0), *pre = res;
    int flag = 0;
    while(l1 && l2){
        int tmp = l1 -> val + l2 -> val + flag;
        pre -> next = new ListNode( tmp % 10 );
        pre = pre -> next;
        flag = tmp / 10;
        l1 = l1 -> next;
        l2 = l2 -> next;
    }
    while(l1){
        int tmp = l1 -> val + flag;
        pre -> next = new ListNode(tmp % 10);
        pre = pre -> next;
        flag = tmp / 10;
        l1 = l1 -> next;
    }
    while(l2){
        int tmp = l2 -> val + flag;
        pre -> next = new ListNode(tmp % 10);
        pre = pre -> next;
        flag = tmp / 10;
        l2 = l2 -> next;
    }
    if(flag)
        pre -> next = new ListNode(1);
    pre = res;
    res = res ->next;
    delete pre;
    return res;
    
}