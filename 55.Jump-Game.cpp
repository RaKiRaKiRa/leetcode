class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = nums[0], end = nums.size() - 1;
        for(int i = 0;i < nums.size(); ++i){
            if(i > max)
                return false;
            int tmp = i + nums[i];
            if(tmp > max){
                max = tmp;
                if(max >= end)
                    return true;
            }
        }
         return true;      

    }
};