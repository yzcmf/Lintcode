/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/minimum-size-subarray-sum
@Language: C++
@Datetime: 16-09-26 23:29
*/

//--Two pointers;
//--Time:O(n);
/*
我们需要定义两个指针left和right，分别记录子数组的左右的边界位置，
然后我们让right向右移,直到子数组和大于等于给定值或者right达到数组末尾，
此时我们更新最短距离,并且将left像右移一位，然后再sum中减去移去的值，
然后重复上面的步骤，直到right到达末尾，且left到达临界位置，
即要么到达边界，要么再往右移动，和就会小于给定值。
*/
// class Solution {
// public:
//     /**
//      * @param nums: a vector of integers
//      * @param s: an integer
//      * @return: an integer representing the minimum size of subarray
//      */
//     int minimumSize(vector<int> &nums, int s) {
//         // write your code here
//         if(nums.empty()) return -1;
//         int left = 0;
//         int right= 0;
//         int len = nums.size();
//         int res = len+1;
//         int sum = 0;
        
//         while(right<len)
//         {
//             while(sum<s && right<len)
//             {
//                 sum += nums[right];
//                 right++;
//             }
            
//             while(sum>=s)
//             {
//                 res = min(res,right-left);
//                 sum -= nums[left];
//                 left++;
//             }
//         }
        
//         return res == len+1 ? -1 : res;
//     }
// };

//---Binary Search:O(nlogn);
/*
下面我们再来看O(nlogn)的解法，这个解法要用到二分查找法，
思路是，我们建立一个比原数组长一位的sums数组，
其中sums[i]表示nums数组中[0, i-1]的和，
然后我们对于sums中每一个值sums[i],用二分查找法找到子数组的右边界位置，
使该子数组之和大于或者等于sums[i]+s,然后我们更新最短长度的距离即可。
*/
class Solution {
public:
    int minimumSize(vector<int>& nums,int s) {
        int len = nums.size();
        vector<int>sums(len+1,0);
        int res = len + 1;
        for (int i = 1; i < len + 1; i++) 
        sums[i] = sums[i - 1] + nums[i - 1];
        
        for (int i = 0; i < len + 1; i++) {
            int right = searchRight(i+1,len,sums[i]+s,sums);
            if (right == len + 1) break;
            if (res > right - i) res = right - i;
        }
        return res == len + 1 ? -1 : res;
    }

    int searchRight(int left, int right, int key, vector<int>& sums) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (sums[mid] >= key) right = mid-1;
            else left = mid+1;
        }
        return left;
    }
};
//Good reference: http://www.cnblogs.com/grandyang/p/4501934.html
