/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/wiggle-sort-ii
@Language: C++
@Datetime: 16-10-01 04:17
*/

class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        int n = nums.size(), k = (n+1)/2 -1 , j = n-1; 
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < n; i++) {
            nums[i] = i & 1 ? tmp[j--] : tmp[k--];
        }
    }
};
//http://www.cnblogs.com/grandyang/p/5139057.html
// O(1) space
// class Solution {
// public:
//     void wiggleSort(vector<int>& nums) {
//         #define A(i) nums[(1 + 2 * i) % (n | 1)]
//         int n = nums.size(), i = 0, j = 0, k = n - 1;
//         auto midptr = nums.begin() + n / 2;
//         nth_element(nums.begin(), midptr, nums.end());
//         int mid = *midptr;
//         while (j <= k) {
//             if (A(j) > mid) swap(A(i++), A(j++));
//             else if (A(j) < mid) swap(A(j), A(k--));
//             else ++j;
//         }
//     }
// };