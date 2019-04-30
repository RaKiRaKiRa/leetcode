/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */
class Solution {
public:
    bool isPalin(string &s, int beg, int end){
        while(beg < end){
            if(s[beg++] != s[end--])
                return false;
        }
        return true;
    }
    void func(int beg, int &sz, string &s, vector<string> &cur, vector<vector<string>> &res){
        if(beg >= sz) return;
        for(int i = beg;i < sz; ++i){
            if(isPalin(s, beg, i)){
                cur.push_back(s.substr(beg, i - beg + 1));
                if(i == sz - 1) 
                    res.push_back(cur);
                else
                    func(i + 1, sz, s, cur, res);
                cur.pop_back();
            }
     
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        int sz = s.size();
        func(0, sz, s, cur, res);
        return res;
    }
};

