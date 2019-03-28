/*
https://leetcode.com/problems/two-sum/
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
    unordered_map<int, int> record;
    for(int i = 0; i <nums.size(); ++i){
        int find = target - nums[i];
        if(record.find(find) != record.end())
            return {record[find] , i};
        record[nums[i]] = i;
    }
    return ;
}