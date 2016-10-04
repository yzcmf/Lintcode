/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/kth-smallest-number-in-sorted-matrix
@Language: C++
@Datetime: 16-09-22 23:55
*/

// -- AC (O(n^2))
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        priority_queue<int, vector<int>> pq;
        //From the smallest to the largest by default;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pq.push(matrix[i][j]);
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }
        int result = pq.top();
        return result;
    }
};

//https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/kth-smallest-number-in-sorted-matrix.cpp
