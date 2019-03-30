/*
https://leetcode.com/problems/reverse-integer/
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;
int reverse(int x) {
    if(x > -10 && x < 10)
        return x;
    int f = 1;
    int64_t t = x, res = 0;
    if( x < 0 ){
        t = t * -1;  
        f = -1;
    }
    while(t > 0){
        res *= 10;
        res += t % 10;
        t /= 10;
    }
    res *= f;
     if(res > INT_MAX || res < INT_MIN)
        return 0;
    return res;   

}