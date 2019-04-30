/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */
class Solution {
public:
/*
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sz = gas.size();

        vector<int> change(sz, 0);
        change[sz - 1] = gas[0] - cost[sz - 1];
        for(int i = 0; i < sz - 1; ++i)
            change[i] = gas[i + 1] - cost[i];

        for(int i = 0; i < sz ; ++i){
            if(cost[i] > gas[i])
                continue;
            bool flag = 1;
            int g = gas[i], n = i;
            for(int j = 0; j < sz; ++j, ++n){
                if(n == sz) 
                    n = 0;
                if(g < cost[n]){
                    flag = 0;
                    //i = n;
                    break;
                }
                g += change[n];
                
            }
            if(flag) return i;
        }
        return -1;
    }
*/

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sz = gas.size();
        int sum = gas[sz - 1] - cost[sz - 1];
        int start = sz - 1, end = 0;
        while(start > end){
            //若无法从start到达end,则也无法到达end之后的值,需要调整start使得start可以到达end
            if(sum < 0){
                --start;
                sum += gas[start] - cost[start];
            }
            //若可以从start到达end则说明start可以到达[start,end]任意位置,调整end
            else{
                sum += gas[end] - cost[end];
                ++end;
            }
        }
        return sum < 0 ? -1 : start;
    }


};

