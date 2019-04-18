/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (29.91%)
 * Total Accepted:    223.3K
 * Total Submissions: 742.2K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return vector<int>();
        int top = 0, button = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        int sz = (button + 1) * (right + 1);
        int i = 0, j = 0;
        vector<int> res;
        while(res.size() < sz){
            for(int i = left; i <= right; ++i)
                res.push_back(matrix[top][i]);
            ++top;
            if(res.size() >= sz) break;
            for(int i = top; i <= button; ++i)
                res.push_back(matrix[i][right]);
            --right;
            if(res.size() >= sz) break;
            for(int i = right; i >= left; --i)
                res.push_back(matrix[button][i]);
            --button;
            if(res.size() >= sz) break;
            for(int i = button; i >= top; --i)
                res.push_back(matrix[i][left]);
            ++left;
            
        }

        return res;
    }
};

