/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/maximal-rectangle
@Language: C++
@Datetime: 16-09-24 06:00
*/

class Solution {
public:
    int maximalRectangle(vector<vector<bool>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0), left(n, 0), right(n, n);
        for (int i = 0; i < m; ++i) {
            int cur_left = 0, cur_right = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == true) ++height[j];
                else height[j] = 0;
            }
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == true) left[j] = max(left[j], cur_left);
                else {left[j] = 0; cur_left = j + 1;}
            }
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == true) right[j] = min(right[j], cur_right);
                else {right[j] = n; cur_right = j;}
            }
            for (int j = 0; j < n; ++j) {
                res = max(res, (right[j] - left[j]) * height[j]);
            }
        }
        return res;
    }
};
//Reference: http://www.cnblogs.com/grandyang/p/4322667.html