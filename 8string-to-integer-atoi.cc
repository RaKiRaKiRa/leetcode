/*
https://leetcode.com/problems/string-to-integer-atoi/
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int myAtoi(string str) {
    int beg = 0;
    while(str[beg] == ' ')
        ++beg;
    if(str[beg] == '+' || str[beg] == '-' || ( str[beg] >= '0' && str[beg] <= '9' ))
        ;
    else
        return 0;
    int64_t res = 0;
    int f = 1; 
    if(str[beg] == '-'){
        f = -1;
        ++beg;
    }
    else if(str[beg] == '+')
        ++beg;
    while(beg < str.size() && (str[beg] >= '0' && str[beg] <= '9')){
        res *= 10;
        res += str[beg] - '0';
        ++beg;
        if(res > INT_MAX)
            if(f == 1)
                return INT_MAX;
            else if(f == -1)
                return INT_MIN;
    }
    res *= f;
    return res;
}