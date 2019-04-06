/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (31.52%)
 * Total Accepted:    401.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
// 暴力
/*
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        int i = 0;
        for( ; i < haystack.size(); ++i){
            if(haystack[i] == needle[0]){
                int flag = 1;
                for(int j = 1; j < needle.size(); ++j){
                    if(haystack[i + j] != needle[j]){
                        flag = 0;
                        break;
                    }      
                }
                if(flag)
                    return i;
            }
        }
        return -1;
    }
};
*/


//KMP
/*
    size_t与int直接比较
从语法角度，当然可以。
多逻辑角度，最好不要直接比较。因为size_t是非负的，int类型是可以为负的，如果拿一个非负的size_t与一个负的int进行比较，你会得到一个目瞪口呆的结果。
所以，比较之前，一定确保int也是非负的。

实际上，在实际工程实践中，有很多有多年经验的人仍然会犯这类错误。防不胜防。
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0, sz = needle.size();
        
        int *next = new int[sz];
        getNext(next, needle);

        while( i < haystack.size() && j < needle.size() ){
            if(haystack[i] == needle[j]){
                ++i;
                ++j;
            }
            else{
                j = next[j];
            }

        }
        if(j == needle.size())
            return i - j;
        return -1;
    }

    void getNext(int *next, string &needle){
        int j = 0, k = -1;
        next[0] = -1;
        
        while(j < needle.size() - 1){
            
            if( k == -1 || needle[j] == needle[k]){
                if(needle[++j] == needle[++k])
                    next[j] = next[k];
                else
                {
                    next[j] = k;
                }
                
            }
            else{
                k = next[k];
            }
        }
    }
};

