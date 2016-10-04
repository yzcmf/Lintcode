/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/the-smallest-difference
@Language: C++
@Datetime: 16-10-01 03:46
*/

// -- SomeWhat similar to Merge sort problem;
class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
  int smallestDifference(vector<int>& A, vector<int>& B) {
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  
  int res = INT_MAX;
  int i = 0, j = 0;
  
  while(i < A.size() && j < B.size()) {
    int diff = (A[i] - B[j]);
    if(diff == 0) return 0; // Enhance the time efficient;
    res = min(res, abs(diff));
    if(diff < 0) i ++;
    else j++;
  }
  
  while(i < A.size()) {
    res = min(res, abs(A[i] - B[j - 1]));
    i++;
  }
  
  while(j < B.size()) {
    res = min(res, abs(A[i - 1] - B[j]));
    j++;
  }
  
  return res;
  }
  
};
