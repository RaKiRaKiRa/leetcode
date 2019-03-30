/*
https://leetcode.com/problems/longest-palindromic-substring/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// too low
void be_Palindrome1(string &s, int k,string &res){
    int sz = 1, i; 
    for( i = 1; ; ++i ){
        if( k - i >= 0 && k + i < s.size() && s[k - i] == s[k + i])
            sz += 2;
        else 
            break;
    }
    if( sz > res.size())
        res = s.substr(k - i + 1, sz);
}

void be_Palindrome2(string &s, int k,string &res){
    int sz = 0, i;
    for( i = 0; ; ++i ){
        if( k - i >= 0 && k + i + 1 < s.size() && s[k - i] == s[k + i + 1])
            sz += 2;
        else break;
    }
    if( sz > res.size())
        res = s.substr(k - i + 1, sz);
}



string longestPalindrome(string s) {
    if( s.size() <= 1 )
        return s;
    string res = string();
       
    for( int i = 0; i < s.size(); ++i ){
        be_Palindrome1(s, i, res);
        be_Palindrome2(s, i, res);
    }
    return res;
}


//best
string longestPalindrome(string s) {
    if( s.size() <= 1 )
        return s;
    int maxLen = 0, left, right, beg;
    string res;
    for( int i = 0 ; i < s.size() - maxLen / 2;++i ){
        left = right = i;
        while( right < s.size() - 1 && s[right] == s[right + 1] )
            ++right;
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            --left;
            ++right;
        }
        if(maxLen < right - left + 1){
            maxLen = right - left + 1;
            beg = left;
        }   
    }
    return s.substr(beg, maxLen);
}


