/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/house-robber-ii
@Language: C++
@Datetime: 16-09-22 22:03
*/

/*
现在房子排成了一个圆圈，则如果抢了第一家，就不能抢最后一家，因为首尾相连了，
所以第一家和最后一家只能抢其中的一家，或者都不抢，那我们这里变通一下，
如果我们把第一家和最后一家分别去掉，各算一遍能抢的最大值，
然后比较两个值取其中较大的一个即为所求。
*/
class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int>& nums) {
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        vector<int> a = nums, b = nums;
        a.erase(a.begin()); 
        b.pop_back();
        return max(rob(a), rob(b));
    }
    int rob(vector<int> &nums) {
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        vector<int> dp{nums[0], max(nums[0], nums[1])};
        for (int i = 2; i < nums.size(); ++i) {
            dp.push_back(max(dp[i - 2] + nums[i], dp[i - 1]));
        }
        return dp.back();
    }
};