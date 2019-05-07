/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */
class LRUCache {
public:
    struct Node{
        int key;
        int value;
        Node *m_next;
        Node *m_pre;
        Node(int k, int v):key(k), value(v){ };
    };

    LRUCache(int capacity) {
        m_Count = 0;
        m_Size = capacity;
        m_head = NULL;
        m_tail = NULL;
    }
  
    int get(int key) {
        if(m_head == NULL)
            return -1;
        map<int, Node*>::iterator it = m_map.find(key);
        if(it == m_map.end())
            return -1;
        push_front(it -> second);
        return it -> second -> value;
    }
    
    void put(int key, int value) {
        //当前链表为空
        if(m_head == NULL){
            Node *p = new Node(key, value);
            m_map[key] = p;
            ++m_Count;
            m_head = m_tail = p;
            return;
        }
        map<int, Node*>::iterator it = m_map.find(key);
        //若未命中
        if(it == m_map.end()){
            //链表未满
            if(m_Count < m_Size){
                Node *p = new Node(key, value);
                m_map[key] = p;
                p -> m_next = m_head;
                m_head -> m_pre = p;
                m_head = p;
                ++m_Count;
            }
            //链表已满
            else{
                m_map.erase(m_tail -> key);
                //只有一个位置
                if(m_head == m_tail){
                    m_head -> key = key;
                    m_head -> value = value;
                    m_map[key] = m_head;
                }
                //有多个位置
                else{
                    Node *p = m_tail;
                    m_tail = m_tail -> m_pre;
                    m_tail -> m_next = NULL;
                    p -> m_next = m_head;
                    m_head -> m_pre = p;
                    m_head = p;
                    p -> key = key;
                    p -> value = value;
                    m_map[key] = p;
                }
            }
        }
        //命中
        else{
            it -> second -> value = value;
            push_front(it -> second);
        }
    }

    void push_front(Node *p){
        if(p == NULL || p == m_head || m_Count == 1)
            return;
        if(p == m_tail){
            p -> m_pre -> m_next = NULL;
            m_tail = p -> m_pre;
            p -> m_pre = NULL;
            p -> m_next = m_head;
            m_head -> m_pre = p;
            m_head = p;
            
        }
        else{
            p -> m_pre -> m_next = p -> m_next;
            p -> m_next -> m_pre = p -> m_pre; 
            p -> m_next = m_head;
            m_head -> m_pre = p;
            m_head = p;
        }
    }
private:
    int m_Count;
    int m_Size;
    Node *m_head;
    Node *m_tail;
    map<int, Node*> m_map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

