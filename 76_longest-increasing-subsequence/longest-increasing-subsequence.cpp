/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/longest-increasing-subsequence
@Language: C++
@Datetime: 16-09-23 12:06
*/

//--- Distinct elements;
//--- DP Solution(O(n^2));
// class Solution {
// public:
//     int longestIncreasingSubsequence(vector<int>& nums) {
//         vector<int>DP(nums.size(), 1);
//         int res = 0;
//         for (int i = 0; i < nums.size(); ++i) {
//             for (int j = 0; j < i; ++j) {
//                 if (nums[i] > nums[j]) {
//                     DP[i] = max(DP[i], DP[j] + 1);
//                 }
//             }
//             res = max(res, DP[i]);
//         }
//         return res;
//     }
// };
//--- Distinct elements;
//--- Binary Search Solution(O(nlogn));
class Solution {
public:
    int longestIncreasingSubsequence(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> ends{nums[0]};
        for (auto a : nums) {
            if (a < ends[0]) ends[0] = a;
            else if (a > ends.back()) ends.push_back(a);
            else {
                int left = 0, right = ends.size();
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (ends[mid] < a) left = mid + 1;
                    else right = mid;
                }
                ends[right] = a;
            }
        }
        return ends.size();
    }
};
//Good reference: http://www.cnblogs.com/grandyang/p/4938187.html