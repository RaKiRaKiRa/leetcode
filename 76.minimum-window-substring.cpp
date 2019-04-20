/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (30.18%)
 * Total Accepted:    226.3K
 * Total Submissions: 744K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 */
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty())
            return "";
        unordered_map<char, int> ch, tmp;
        //map<char, int> ch, tmp;
        int min_s, min_e, start = 0, end = 0, count = 0;
        for(int i = 0; i < t.size(); ++i){
            ++ch[t[i]];
            ++tmp[t[i]];
        }
            
        //tmp = ch;
        int min_w = INT_MAX, cur_w = 0;
        while(end < s.size()){
            if( tmp.find( s[end] ) == tmp.end() ){
                ++end;
                continue;
            }
            --tmp[ s[end] ];
            if(tmp[ s[end] ] >= 0 )
                ++count;
            if( count == t.size() ){
                while(start != end){
                    if(ch.find(s[start]) == ch.end()){
                        ++start;
                        continue;
                    }
                    if(tmp[s[start]] < 0){
                        ++tmp[s[start]];
                        ++start;
                        
                        continue;
                    }
                    else
                        break;
                }
                cur_w = end - start + 1;
                if(cur_w < min_w){
                    min_s = start;
                    min_e = end;
                    min_w = cur_w;
                }
            }
            ++end;
        }
        if(min_w == INT_MAX) return "";
        //cout<< min_w;
        return s.substr(min_s, min_w);

    }
};

