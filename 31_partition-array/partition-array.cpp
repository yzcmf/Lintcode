/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/partition-array
@Language: C++
@Datetime: 16-09-25 20:04
*/

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        // -- Common Method;
        // int n = nums.size();
        // if(n == 0) return 0;
        // int i;
        
        // for(i=0;i<n;i++)
        // {
        //   int index = i;    
        //   while(nums[index]>=k && index<=(n-1))index++;
        //   if(index == n) break;
        //   swap(nums[i],nums[index]);
        // }
        // return i;
        
        //Two pointers;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (nums[left] < k) {
                left++;
            } else if (nums[right] >= k) {
                right--;
            } else {
              swap(nums[left++], nums[right--]);
            }
        }
        return left;
    }
};