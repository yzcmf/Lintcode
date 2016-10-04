/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/backpack-vi
@Language: C++
@Datetime: 16-09-20 05:44
*/

/*
我们需要一个一维数组dp，其中dp[i]表示目标数为i的解的个数，
然后我们从1遍历到target，对于每一个数i，遍历nums数组，
如果i>=x, dp[i] += dp[i - x]。这个也很好理解，
比如说对于[1,2,3] 4，这个例子，当我们在计算dp[3]的时候，
3可以拆分为1+x，而x即为dp[2]，3也可以拆分为2+x，此时x为dp[1]，
3同样可以拆为3+x，此时x为dp[0]，我们把所有的情况加起来就是组成3的所有情况了
如果target远大于nums数组的个数的话，
上面的算法可以做适当的优化，
先给nums数组排个序，然后从1遍历到target，
对于i小于数组中的数字x时，我们直接break掉，
因为后面的数更大，其余地方不变
*/
class Solution {
public:
    /**
     * @param nums an integer array and all positive numbers, no duplicates
     * @param target an integer
     * @return an integer
     */
    int backPackVI(vector<int>& nums, int target) {
        // Write your code here
        if(nums.empty()) return 0;
        vector<int>dp(target+1);
        dp[0]=1;
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<=target;i++)
        {
            for(auto a:nums)
            {
                if(a>i) break;
                else
                dp[i] = dp[i] +dp[i-a];
            }
        }
        return dp[target];
    }
};