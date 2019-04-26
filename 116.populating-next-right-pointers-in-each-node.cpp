/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

/*
class Solution {
public:
    struct TN{
        Node* node;
        int lv;
        TN(int l, Node* n):node(n), lv(l){};
    };
    Node* connect(Node* root) {
        if(!root) return NULL;
        int l = 1;
        TN tn(1, root);    
        queue<TN> que;
        Node *last = root, *cur = root;
        if(cur -> left)
            que.push(TN(2, cur -> left));
        if(cur -> right)
            que.push(TN(2,cur -> right));

        while(que.size()){
            last = cur;
            tn = que.front();
            que.pop();
            cur = tn.node;
            if(l == tn.lv)
                last -> next = cur;
            else{
                last -> next = NULL;
                ++l;
            }
                
            if(cur -> left)
                que.push(TN(l + 1, cur -> left));
            if(cur -> right)
                que.push(TN(l + 1, cur -> right));
        }
        return root;
    }
};
*/

class Solution {
public:

    Node* connect(Node* root) {
        if(!root) return NULL;
        Node *cur;
        queue<Node*> que;
        que.push(root);
        while(que.size()){
            int size = que.size();
            Node *pre = NULL;
            while(size--){
                cur = que.front();
                que.pop();
                if(pre)
                    pre -> next = cur;
                pre = cur;
                if(cur -> left)
                    que.push(cur -> left);
                if(cur -> right)
                    que.push(cur -> right);
            }
            cur -> next = NULL;
        }
        return root;
    }
};

