/*
https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

double find_kth(vector<int>& nums1, vector<int>& nums2,int l1,int l2,int k){
    if( l1 >= nums1.size() )
        return nums2[ k + l2 - 1 ];
    if( l2 >= nums2.size())
        return nums1[ k + l1 - 1 ];

    if( k == 1)
        return nums1[l1] < nums2[l2] ? nums1[l1] : nums2[l2] ;
    
    int p1 = l1 + k / 2 - 1 >= nums1.size() ? INT_MAX : nums1[l1 + k / 2 - 1];
    int p2 = l2 + k / 2 - 1 >= nums2.size() ? INT_MAX : nums2[l2 + k / 2 - 1];

    if( p1 > p2 )
        return find_kth(nums1 ,nums2, l1, l2 + k / 2, k - k / 2);
    return find_kth(nums1 ,nums2, l1 + k / 2 , l2, k - k / 2);
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int sz = nums1.size() + nums2.size();
    if(sz % 2)
        return find_kth( nums1, nums2, 0, 0, sz / 2 + 1);
    return (find_kth( nums1, nums2, 0, 0, sz / 2 + 1) + find_kth( nums1, nums2, 0, 0, sz / 2 )) / 2;
}