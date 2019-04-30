/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        int num, res = 0, b, l, count;
        while(hash.size()){
            num = *(hash.begin());
            hash.erase(num);
            b = num + 1;
            l = num - 1;
            count = 1;
            while(hash.find(l) != hash.end()){
                ++count;
                hash.erase(l--);
            }
            while(hash.find(b) != hash.end()){
                ++count;
                hash.erase(b++);
            }
            if(count > res) res = count;
        }
        return res;
    }
};

